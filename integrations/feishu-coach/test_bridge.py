"""Boundary checks for ownership, redelivery and mobile code formatting."""
from pathlib import Path
import importlib.util
import json
import re
import tempfile
import threading
import time
import unittest

spec = importlib.util.spec_from_file_location("coach_bridge", Path(__file__).with_name("bridge.py"))
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class GitSaveAndDailyPushTests(unittest.TestCase):
    """2026-11-09：模型沙箱写不了 .git，由程序按 git-save 块提交；每日推送由程序定时排队。"""

    def test_git_save_block_is_extracted_and_limited_to_us_paths(self):
        text = "做完了。\n\n```git-save\n{\"paths\": [\"us/cpp/0125.valid-palindrome/solution.cpp\", \"us/cpp/0125.valid-palindrome/learning.md\"], \"message\": \"feat(leetcode): 125 valid palindrome\"}\n```\n\n下一题见。"
        cleaned, request = module.extract_git_save(text)
        self.assertEqual(cleaned, "做完了。\n\n下一题见。")
        self.assertEqual(request["paths"], ["us/cpp/0125.valid-palindrome/solution.cpp", "us/cpp/0125.valid-palindrome/learning.md"])
        self.assertEqual(request["message"], "feat(leetcode): 125 valid palindrome")
        self.assertEqual(module.extract_git_save("没有块")[1], None)
        for bad in ["us/.env", "../secret", "cpp/old.cpp", "/etc/passwd", "us/x/../../.env"]:
            _, rejected = module.extract_git_save("```git-save\n" + json.dumps({"paths": [bad], "message": "m"}) + "\n```")
            self.assertIn("error", rejected, bad)
        _, broken = module.extract_git_save("```git-save\nnot json\n```")
        self.assertIn("error", broken)

    def test_daily_push_due_once_per_local_day_inside_window(self):
        from datetime import datetime, timezone as tz
        config = {"daily_push": {"enabled": True, "hour": 9, "minute": 0, "tz": "Asia/Shanghai", "latest_hour": 22}}
        at = lambda h, m=0: datetime(2026, 11, 9, h - 8, m, tzinfo=tz.utc)  # 北京时间 h:m
        self.assertIsNone(module.daily_push_due(config, at(8, 59), ""))
        self.assertEqual(module.daily_push_due(config, at(9, 0), ""), "2026-11-09")
        self.assertEqual(module.daily_push_due(config, at(15, 30), "2026-11-08"), "2026-11-09", "睡过头也在当天补发")
        self.assertIsNone(module.daily_push_due(config, at(9, 5), "2026-11-09"), "当天发过不再发")
        self.assertIsNone(module.daily_push_due(config, at(22, 0), ""), "太晚就不发了")
        self.assertIsNone(module.daily_push_due({}, at(9, 0), ""), "没开就不发")

    def test_daily_push_is_queued_as_owner_turn_without_receipt(self):
        temporary = tempfile.TemporaryDirectory()
        try:
            path = Path(temporary.name)
            bridge = module.Bridge({"owner_id": "ou_owner", "chat_id": "oc_private", "repo": str(path),
                                    "daily_push": {"enabled": True}}, path / "state")
            self.assertTrue(bridge.enqueue_daily_push("2026-11-09"))
            self.assertFalse(bridge.enqueue_daily_push("2026-11-09"), "同一天只排一次")
            with bridge.db() as db:
                row = db.execute("SELECT payload FROM messages").fetchone()
            payload = json.loads(row[0])
            self.assertEqual(payload["synthetic"], "daily_push")
            self.assertIn("每日推送", payload["content"])
            self.assertEqual(bridge.meta("daily_push_date"), "2026-11-09")
        finally:
            temporary.cleanup()


class BoundaryTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.path = Path(self.temporary.name)
        self.config = {"owner_id": "ou_owner", "chat_id": "oc_private", "repo": str(self.path)}
        self.bridge = module.Bridge(self.config, self.path / "state")

    def tearDown(self):
        self.temporary.cleanup()

    def event(self, **values):
        return {"chat_id": "oc_private", "sender_id": "ou_owner", "sender_type": "user",
                "message_id": "om_first", "message_type": "text", "content": "开始刷题",
                "create_time": "1794074400000", **values}

    def test_only_owner_in_exact_private_group(self):
        self.assertTrue(self.bridge.enqueue(self.event(), "event"))
        for change in [{"sender_id": "ou_other"}, {"chat_id": "oc_other"},
                       {"sender_type": "bot"}, {"deleted": True}, {"message_type": "system"}]:
            self.assertFalse(self.bridge.enqueue(self.event(message_id="om_other", **change), "event"))
        with self.bridge.db() as db:
            self.assertEqual(db.execute("SELECT count(*) FROM messages").fetchone()[0], 1)

    def test_same_message_from_event_and_history_is_queued_once(self):
        self.bridge.enqueue(self.event(), "event")
        history = {"chat_id": "oc_private", "sender": {"id": "ou_owner", "sender_type": "user"},
                   "message_id": "om_first", "msg_type": "text", "content": "开始刷题"}
        self.assertFalse(self.bridge.enqueue(history, "history"))

    def test_history_messages_keep_order_inside_same_minute(self):
        self.bridge.enqueue(self.event(message_id="om_z"), "history")
        self.bridge.enqueue(self.event(message_id="om_a"), "history")
        with self.bridge.db() as db:
            ids = [row[0] for row in db.execute("SELECT id FROM messages ORDER BY created_ms,rowid")]
        self.assertEqual(ids, ["om_z", "om_a"])

    def test_long_code_retains_balanced_fences(self):
        text = "说明\n```cpp\n" + "int value = 123;\n" * 700 + "```\n结束"
        chunks = module.split_reply(text)
        self.assertGreater(len(chunks), 1)
        for chunk in chunks:
            self.assertEqual(sum(line.startswith("```") for line in chunk.splitlines()) % 2, 0)
            self.assertLessEqual(len(chunk), 3350)
        self.assertIn("结束", chunks[-1])

    def test_credentials_and_automatic_remote_images_are_removed(self):
        (self.path / "us").mkdir()
        (self.path / "us/.env").write_text("SESSION=private-test-value-123456789\n")
        result = self.bridge.redact("private-test-value-123456789 ![x](https://example.com/p.png)")
        self.assertNotIn("private-test-value", result)
        self.assertNotIn("https://example.com", result)

    def test_timestamp_formats(self):
        self.assertEqual(module.milliseconds("1794074400"), 1794074400000)
        self.assertEqual(module.milliseconds("1794074400000"), 1794074400000)
        self.assertGreater(module.milliseconds("2026-11-07 12:53"), 0)

    def test_continue_gets_receipt_while_answer_is_still_being_generated(self):
        """Exercise the real queue/worker seam with the user's slow-reply pattern."""
        received = threading.Event()
        release_answer = threading.Event()
        answered = threading.Event()
        sent = []

        def slow_answer(message):
            release_answer.wait(2)
            return "继续第 125 题。"

        def capture_send(text, key, **options):
            sent.append((text, key))
            if text.startswith("收到"):
                received.set()
            else:
                answered.set()
            return {"message_id": "om_reply"}

        self.bridge.ask = slow_answer
        self.bridge.send = capture_send
        module.STOP.clear()
        worker = threading.Thread(target=self.bridge.worker, daemon=True)
        worker.start()
        try:
            self.bridge.enqueue(self.event(content="继续"), "history")
            self.bridge.enqueue(self.event(content="继续"), "event")
            self.assertTrue(received.wait(.5), "No receipt is visible while the coach is working")
            self.assertFalse(answered.is_set())
            release_answer.set()
            self.assertTrue(answered.wait(1))
            self.assertEqual(len(sent), 2)
            self.assertNotEqual(sent[0][1], sent[1][1])
        finally:
            release_answer.set()
            module.STOP.set()
            self.bridge.wake.set()
            worker.join(timeout=3)
            module.STOP.clear()

    def test_polling_speeds_up_during_conversation_and_slows_when_idle(self):
        now = time.time()
        self.assertEqual(self.bridge.poll_interval(now), 20)
        self.bridge.enqueue(self.event(create_time=str(int(now * 1000))), "history")
        self.assertEqual(self.bridge.poll_interval(now), 5)
        self.assertEqual(self.bridge.poll_interval(now + 11 * 60), 20)

    def test_failed_receipt_does_not_suppress_answer(self):
        answered = threading.Event()

        def capture_send(text, key, **options):
            if text.startswith("收到"):
                raise RuntimeError("receipt unavailable")
            answered.set()
            return {"message_id": "om_reply"}

        self.bridge.ask = lambda message: "继续第 125 题。"
        self.bridge.send = capture_send
        module.STOP.clear()
        worker = threading.Thread(target=self.bridge.worker, daemon=True)
        worker.start()
        try:
            self.bridge.enqueue(self.event(content="继续"), "history")
            self.assertTrue(answered.wait(1))
        finally:
            module.STOP.set()
            self.bridge.wake.set()
            worker.join(timeout=3)
            module.STOP.clear()
        with self.bridge.db() as db:
            self.assertEqual(db.execute("SELECT status FROM messages").fetchone()[0], "done")

    def send_body(self, text):
        outgoing = []

        def capture_cli(args, body=None, **options):
            outgoing.append(body)
            return {"message_id": "om_formatted"}

        self.bridge.cli = capture_cli
        self.bridge.send(text, "formatting-check")
        return outgoing[0]

    def assert_pointer_columns(self, text, left, right):
        match = re.search(r"```text\n(.*?)\n```", text, re.S)
        self.assertIsNotNone(match)
        lines = match.group(1).splitlines()
        self.assertTrue(match.group(1).isascii(), "Mixed-width diagram reached the mobile client")
        for name, index in [("left", left), ("right", right)]:
            column = lines[3].index(name)
            self.assertEqual(lines[0][column], str(index))
            self.assertEqual(lines[1][column], "abba"[index])
            self.assertEqual(lines[2][column], "^")
        self.assertLessEqual(max(map(len, lines)), 36)

    def test_real_mobile_diagram_is_repaired_at_outbound_boundary(self):
        # The exact diagram and variable values from the reported Feishu message.
        original = ('先看 "abba"：\n\n```text\n下标：  0  1  2  3\n'
                    '字符：  a  b  b  a\n        ↑        ↑\n       left    right\n```\n\n'
                    '- `left = 0`：指向左边。\n- `right = 3`：指向右边。')
        self.assert_pointer_columns(self.send_body(original), 0, 3)

    def test_structured_pointer_diagrams_keep_both_labels_on_their_characters(self):
        for left in range(4):
            for right in range(4):
                if left == right:
                    continue
                source = "```pointer-diagram\n" + json.dumps({"text": "abba", "left": left, "right": right}) + "\n```"
                body = self.send_body(source)
                self.assertNotIn("pointer-diagram", body)
                self.assert_pointer_columns(body, left, right)

    def test_real_cpp_code_preserves_exact_indentation(self):
        code = '```cpp\nclass Solution {\npublic:\n    bool check() {\n\treturn true; // 中文注释\n    }\n};\n```'
        self.assertEqual(self.send_body(code), code)

    def test_resumed_conversation_gets_current_format_rules(self):
        prompt = self.bridge.prompt_for(self.event(content="继续"), resuming=True)
        self.assertIn("本轮飞书显示规则", prompt)
        self.assertIn("pointer-diagram", prompt)

    def test_invalid_pointer_positions_never_produce_a_false_arrow(self):
        for data in [{"text": "abba", "left": -1, "right": 3},
                     {"text": "abba", "left": 0, "right": 4}]:
            body = self.send_body("```pointer-diagram\n" + json.dumps(data) + "\n```")
            self.assertNotIn("pointer-diagram", body)
            self.assertNotIn("^", body)
            self.assertIn("下标", body)

    def test_long_or_coincident_positions_use_explicit_index_mapping(self):
        long_diagram = module.pointer_diagram("abcdefghij", 1, 8)
        self.assertIn('left  -> s[1] = "b"', long_diagram)
        self.assertIn('right -> s[8] = "i"', long_diagram)
        self.assertIn('left = right = 2', module.pointer_diagram("abba", 2, 2))


if __name__ == "__main__":
    unittest.main()
