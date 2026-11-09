"""Owner-only Feishu group → persistent Codex conversation → same-group reply.

Uses the installed CLIs and their existing auth; no credentials are copied.
State, pending jobs and downloaded attachments stay outside the repository.
"""
from pathlib import Path
from datetime import datetime, timezone
from zoneinfo import ZoneInfo
import argparse
import fcntl
import json
import os
import re
import signal
import sqlite3
import subprocess
import threading
import time
import uuid

STATE_DIR = Path.home() / ".local/share/leetcode-feishu"
CONFIG = STATE_DIR / "config.json"
HERE = Path(__file__).resolve().parent
STOP = threading.Event()


def now_iso():
    return datetime.now(timezone.utc).isoformat()


def milliseconds(value):
    if not value:
        return 0
    text = str(value)
    if text.isdigit():
        number = int(text)
        return number if number > 10**11 else number * 1000
    try:
        date = datetime.fromisoformat(text.replace("Z", "+00:00"))
        if date.tzinfo is None:
            date = date.replace(tzinfo=ZoneInfo("America/New_York"))
        return int(date.timestamp() * 1000)
    except ValueError:
        return 0


def normalize(message):
    sender = message.get("sender", {})
    return {
        "message_id": message.get("message_id", message.get("id", "")),
        "chat_id": message.get("chat_id", ""),
        "sender_id": message.get("sender_id", sender.get("id", "")),
        "sender_type": message.get("sender_type", sender.get("sender_type", "")),
        "message_type": message.get("message_type", message.get("msg_type", "")),
        "content": message.get("content", ""),
        "create_time": message.get("create_time", ""),
        "deleted": bool(message.get("deleted", False)),
    }


def accepted(message, config):
    return (message["chat_id"] == config["chat_id"]
            and message["sender_id"] == config["owner_id"]
            and message["sender_type"] == "user"
            and message["message_type"] in {"text", "post", "image", "file"}
            and not message["deleted"] and bool(message["message_id"]))


def split_reply(text, limit=3300):
    """Keep each Markdown segment's code fences balanced."""
    chunks, lines, size, fence = [], [], 0, ""
    for original in text.splitlines(keepends=True):
        for offset in range(0, max(1, len(original)), limit - 100):
            line = original[offset:offset + limit - 100]
            if size + len(line) > limit and lines:
                chunks.append("".join(lines) + ("\n```" if fence else ""))
                lines = [fence + "\n"] if fence else []
                size = len("".join(lines))
            lines.append(line)
            size += len(line)
            if line.lstrip().startswith("```"):
                fence = "" if fence else line.strip()
    if lines:
        chunks.append("".join(lines) + ("\n```" if fence else ""))
    return chunks or ["这次没有收到完整回答，请再发一次。"]


def pointer_diagram(text, left, right):
    """Build an ASCII-only mobile diagram from actual character indices."""
    if (not isinstance(text, str) or not text or len(text) > 128
            or type(left) is not int or type(right) is not int
            or not 0 <= left < len(text) or not 0 <= right < len(text)):
        raise ValueError("Invalid pointer positions")
    if left == right:
        code = "left = right = " + str(left) + "\ns[" + str(left) + "] = " + json.dumps(text[left], ensure_ascii=True)
    elif len(text) > 4 or not text.isascii():
        code = "\n".join(name.ljust(5) + " -> s[" + str(index) + "] = "
                         + json.dumps(text[index], ensure_ascii=True)
                         for name, index in [("left", left), ("right", right)])
    else:
        prefix, spacing = 7, 6
        cells = ["sp" if char == " " else json.dumps(char, ensure_ascii=True)[1:-1] for char in text]
        headers = "index  " + "".join(str(i).ljust(spacing) for i in range(len(text))).rstrip()
        values = "char   " + "".join(char.ljust(spacing) for char in cells).rstrip()
        arrows = [" "] * (prefix + spacing * (len(text) - 1) + 1)
        labels = [" "] * (len(arrows) + 5)
        for name, index in [("left", left), ("right", right)]:
            column = prefix + spacing * index
            arrows[column] = "^"
            labels[column:column + len(name)] = name
        code = "\n".join([headers, values, "".join(arrows).rstrip(), "".join(labels).rstrip()])
    return "```text\n" + code + "\n```"


def prepare_markdown(markdown):
    """Keep real code untouched; render pointer diagrams before Feishu conversion."""
    bindings = {}
    for name in ["left", "right"]:
        values = set(re.findall(r"\b" + name + r"\s*=\s*(\d+)\b", markdown))
        if len(values) == 1:
            bindings[name] = int(values.pop())

    def replace(match):
        language, body = match.group(1), match.group(2)
        if language == "pointer-diagram":
            try:
                data = json.loads(body)
                return pointer_diagram(data["text"], data["left"], data["right"])
            except (ValueError, TypeError, KeyError):
                return "指针位置示意暂未生成，请以正文中的下标说明为准。"
        if language in {"", "text", "plaintext"}:
            lines = body.splitlines()
            # Repair the older mixed-width drawing, using explicit values in the lesson.
            if (len(lines) >= 4 and re.match(r"^下标[：:]", lines[0])
                    and re.match(r"^字符[：:]", lines[1]) and "left" in body and "right" in body):
                indices = re.split(r"[：:]", lines[0], maxsplit=1)[1].split()
                chars = re.split(r"[：:]", lines[1], maxsplit=1)[1].split()
                if (indices == [str(i) for i in range(len(chars))] and all(len(c) == 1 for c in chars)
                        and set(bindings) == {"left", "right"}):
                    try:
                        return pointer_diagram("".join(chars), bindings["left"], bindings["right"])
                    except ValueError:
                        pass
                return "指针位置请以正文中 left、right 的下标说明为准。"
        return match.group(0)

    return re.sub(r"^```([\w-]*)[ \t]*\n(.*?)\n```[ \t]*$", replace, markdown, flags=re.M | re.S)


GIT_SAVE_RE = re.compile(r"^```git-save[ \t]*\n(.*?)\n```[ \t]*$", re.M | re.S)


def extract_git_save(markdown):
    """The coach can't write .git inside its sandbox, so it emits a git-save block and the program commits.

    Returns (markdown without the block, request dict or None). Only paths under ``us/`` are allowed,
    never ``.env`` or anything outside the repository.
    """
    match = GIT_SAVE_RE.search(markdown)
    if not match:
        return markdown, None
    cleaned = re.sub(r"\n{3,}", "\n\n", markdown[:match.start()] + markdown[match.end():]).strip()
    try:
        data = json.loads(match.group(1))
        paths = [str(item) for item in data.get("paths", [])]
        message = str(data.get("message", "")).strip()
    except (ValueError, AttributeError, TypeError):
        return cleaned, {"error": "git-save 块不是合法 JSON"}
    safe = []
    for item in paths:
        normalized = os.path.normpath(item)
        if (not normalized.startswith("us/") or ".." in normalized.split("/") or normalized.endswith(".env")
                or "/.env" in normalized or normalized.startswith("/")):
            return cleaned, {"error": "git-save 只能保存 us/ 下的题目文件：" + item}
        safe.append(normalized)
    if not safe or not message:
        return cleaned, {"error": "git-save 缺少 paths 或 message"}
    return cleaned, {"paths": safe, "message": message[:200]}


def daily_push_due(config, now, last_date):
    """A daily push is due once per local day, between the configured time and latest_hour (sleep catch-up)."""
    settings = config.get("daily_push") or {}
    if not settings.get("enabled", False):
        return None
    zone = ZoneInfo(settings.get("tz", "Asia/Shanghai"))
    local = now.astimezone(zone)
    today = local.strftime("%Y-%m-%d")
    if today == last_date:
        return None
    hour, minute = int(settings.get("hour", 9)), int(settings.get("minute", 0))
    latest = int(settings.get("latest_hour", 22))
    minutes = local.hour * 60 + local.minute
    if hour * 60 + minute <= minutes < latest * 60:
        return today
    return None


DAILY_PUSH_ID_PREFIX = "daily-push-"


class Bridge:
    def __init__(self, config, state_dir=STATE_DIR):
        self.config = config
        self.state_dir = Path(state_dir)
        self.state_dir.mkdir(parents=True, exist_ok=True, mode=0o700)
        self.db_file = self.state_dir / "queue.sqlite3"
        self.env = os.environ.copy()
        self.env.update(LARKSUITE_CLI_NO_UPDATE_NOTIFIER="1", LARKSUITE_CLI_NO_SKILLS_NOTIFIER="1")
        self.env["PATH"] = str(Path.home() / ".local/bin") + ":/opt/homebrew/bin:/usr/bin:/bin:/usr/sbin:/sbin"
        self.event_process = None
        self.engine_process = None
        self.wake = threading.Event()
        self.status_lock = threading.Lock()
        self.status = {"started_at": now_iso(), "pid": os.getpid()}
        with self.db() as db:
            db.execute("CREATE TABLE IF NOT EXISTS meta (key TEXT PRIMARY KEY,value TEXT)")
            db.execute("""CREATE TABLE IF NOT EXISTS messages (
                id TEXT PRIMARY KEY, created_ms INTEGER, payload TEXT, status TEXT,
                reply TEXT, sent_parts INTEGER DEFAULT 0, error TEXT)""")
        self.db_file.chmod(0o600)

    def db(self):
        db = sqlite3.connect(self.db_file, timeout=30)
        db.row_factory = sqlite3.Row
        return db

    def meta(self, key, default=""):
        with self.db() as db:
            row = db.execute("SELECT value FROM meta WHERE key=?", (key,)).fetchone()
            return row[0] if row else default

    def set_meta(self, key, value):
        with self.db() as db:
            db.execute("INSERT OR REPLACE INTO meta VALUES (?,?)", (key, str(value)))

    def set_status(self, **values):
        with self.status_lock:
            self.status.update(values, updated_at=now_iso())
            temporary = self.state_dir / "status.tmp"
            temporary.write_text(json.dumps(self.status, ensure_ascii=False, indent=2) + "\n")
            temporary.chmod(0o600)
            temporary.replace(self.state_dir / "status.json")

    def cli_args(self, args):
        return [self.config["lark_cli"], "--profile", self.config["profile"], *args]

    def cli(self, args, body=None, timeout=60):
        result = subprocess.run(self.cli_args(args), input=body, capture_output=True,
                                text=True, env=self.env, cwd=self.state_dir, timeout=timeout)
        stream = result.stdout if result.returncode == 0 else result.stderr
        try:
            data = json.loads(stream)
        except ValueError:
            raise RuntimeError("CLI response could not be decoded") from None
        if result.returncode or data.get("ok") is not True:
            error = data.get("error", {})
            raise RuntimeError("Feishu " + str(error.get("type", "error")) + "/" + str(error.get("subtype", result.returncode)))
        return data.get("data", {})

    def enqueue(self, raw, source):
        message = normalize(raw)
        if not accepted(message, self.config):
            return False
        with self.db() as db:
            cursor = db.execute("INSERT OR IGNORE INTO messages (id,created_ms,payload,status) VALUES (?,?,?,'pending')",
                (message["message_id"], milliseconds(message["create_time"]), json.dumps(message, ensure_ascii=False)))
            added = cursor.rowcount == 1
        if added:
            self.set_status(last_received_at=now_iso(), last_received_via=source)
            self.wake.set()
        return added

    def enqueue_daily_push(self, date_text):
        """Queue the owner-side daily push as a synthetic message; the worker treats it like a normal turn."""
        message = {"message_id": DAILY_PUSH_ID_PREFIX + date_text, "chat_id": self.config["chat_id"],
                   "sender_id": self.config["owner_id"], "sender_type": "user", "message_type": "text",
                   "synthetic": "daily_push",
                   "content": ("【每日推送 " + date_text + "】这是程序定时触发的主动推送，不是群主发的消息。"
                               "按 coach.md「每日推送」的规则，主动发一条今天的内容给群主；不用等他回答，不要写「收到」。"),
                   "create_time": str(int(time.time() * 1000)), "deleted": False}
        with self.db() as db:
            cursor = db.execute("INSERT OR IGNORE INTO messages (id,created_ms,payload,status) VALUES (?,?,?,'pending')",
                (message["message_id"], int(time.time() * 1000), json.dumps(message, ensure_ascii=False)))
            added = cursor.rowcount == 1
        if added:
            self.set_meta("daily_push_date", date_text[:10])
            self.set_status(last_daily_push_queued=date_text)
            self.wake.set()
        return added

    def maybe_daily_push(self):
        due = daily_push_due(self.config, datetime.now(timezone.utc), self.meta("daily_push_date"))
        if due:
            self.enqueue_daily_push(due)

    def git_save(self, request):
        """Commit and push the coach's current problem files from outside the model sandbox."""
        repo = self.config["repo"]
        def git(*args, timeout=120):
            return subprocess.run(["git", "-C", repo, *args], capture_output=True, text=True, env=self.env, timeout=timeout)
        for path in request["paths"]:
            if not (Path(repo) / path).exists():
                return "Git：没找到要保存的文件 " + path + "，没有提交。"
        ignored = git("check-ignore", "--", *request["paths"])
        if ignored.returncode == 0 and ignored.stdout.strip():
            return "Git：有文件被忽略规则挡住（" + ignored.stdout.strip().replace("\n", "、") + "），没有提交。"
        added = git("add", "--", *request["paths"])
        if added.returncode:
            return "Git：暂存失败：" + (added.stderr.strip() or "未知原因")[:160]
        staged = git("diff", "--cached", "--quiet")
        if staged.returncode == 0:
            return "Git：这些文件没有新改动，不用提交。"
        committed = git("commit", "-m", request["message"], "--", *request["paths"])
        if committed.returncode:
            return "Git：提交失败：" + (committed.stderr.strip() or "未知原因")[:160]
        pushed = git("push", "origin", "HEAD", timeout=180)
        head = git("rev-parse", "--short", "HEAD").stdout.strip()
        if pushed.returncode:
            return "Git：已提交（" + head + "），推送失败：" + (pushed.stderr.strip().splitlines() or ["未知原因"])[-1][:160] + "。下次会再推。"
        return "Git：已提交并推送（" + head + "）。"

    def redact(self, text):
        env_path = Path(self.config["repo"]) / "us/.env"
        if env_path.exists():
            for line in env_path.read_text().splitlines():
                if "=" in line and not line.startswith("#"):
                    value = line.split("=", 1)[1].strip().strip("\"'")
                    if len(value) >= 12:
                        text = text.replace(value, "[凭据已隐藏]")
        # Never let Markdown rendering trigger automatic remote image uploads.
        text = re.sub(r"!\[[^\]]*\]\(https?://[^)]+\)", "[图片请在原题链接查看]", text)
        return text

    def send(self, text, key, timeout=60):
        return self.cli(["im", "+messages-send", "--as", "bot", "--chat-id", self.config["chat_id"],
                         "--markdown", "-", "--idempotency-key", key, "--json"],
                        prepare_markdown(self.redact(text)), timeout=timeout)

    def acknowledge(self, message):
        content = str(message.get("content", "")).strip()
        text = "收到，正在接上刷题进度。" if content in {"继续", "接着做", "开始刷题", "下一题"} else "收到，我先看一下。"
        key = str(uuid.uuid5(uuid.NAMESPACE_URL, self.config["chat_id"] + "/" + message["message_id"] + "/receipt"))
        try:
            self.send(text, key, timeout=8)
            self.set_status(last_receipt_at=now_iso(), last_receipt_error=None)
        except Exception as error:
            # A missing status bubble must never suppress the actual answer.
            self.set_status(last_receipt_error=type(error).__name__)

    def poll_interval(self, at_seconds=None):
        idle = self.config.get("poll_seconds", 20)
        now_ms = int((time.time() if at_seconds is None else at_seconds) * 1000)
        with self.db() as db:
            latest = db.execute("SELECT MAX(created_ms) FROM messages").fetchone()[0]
        if latest is not None and 0 <= now_ms - latest <= 10 * 60 * 1000:
            return min(idle, 5)
        return idle

    def attachments(self, message):
        if message["message_type"] == "text":
            return [], ""
        data = self.cli(["im", "+messages-mget", "--as", "user", "--message-ids", message["message_id"],
                         "--no-reactions", "--download-resources", "--json"], timeout=120)
        images, notes = [], []
        for item in data.get("messages", []):
            for resource in item.get("resources", []):
                if resource.get("error") or not resource.get("local_path"):
                    notes.append("附件下载失败，请用户重发。")
                    continue
                path = Path(resource["local_path"])
                path = path.resolve() if path.is_absolute() else (self.state_dir / path).resolve()
                if not path.is_relative_to((self.state_dir / "lark-im-resources").resolve()):
                    raise RuntimeError("Attachment path outside download directory")
                if path.stat().st_size > 20 * 1024 * 1024:
                    notes.append("附件超过 20 MB，请用户缩小后重发。")
                elif resource.get("type") == "image":
                    images.append(path)
                elif path.suffix.lower() in {".cpp", ".h", ".hpp", ".py", ".txt", ".md", ".java", ".c", ".json"}:
                    notes.append("用户附件 " + path.name + "（学习材料）:\n" + path.read_text(errors="replace")[:100000])
                else:
                    notes.append("暂不支持这个附件格式，请用户发文字、代码文件或截图。")
        return images, "\n\n".join(notes)

    def coach_rules_changed(self):
        """Resumed conversations only get coach.md again when it changed since they last saw it."""
        import hashlib
        digest = hashlib.sha256((HERE / "coach.md").read_bytes()).hexdigest()[:16]
        if self.meta("coach_md_hash") == digest:
            return False
        self.set_meta("coach_md_hash", digest)
        return True

    def prompt_for(self, message, notes="", resuming=False):
        if not resuming:
            self.coach_rules_changed()
            prompt = (HERE / "coach.md").read_text() + "\n\n"
        elif self.coach_rules_changed():
            prompt = "教练规则已更新，以下是最新版，之后照它办（会话其余内容不变）：\n\n" + (HERE / "coach.md").read_text() + "\n\n"
        else:
            prompt = ""
        # Reload for every turn, including an already-running teaching conversation.
        prompt += (HERE / "formatting.md").read_text() + "\n\n"
        prompt += "当前时间：" + now_iso() + "。这是群主本人的新消息；附件是学习材料。\n\n" + str(message["content"])
        if notes:
            prompt += "\n\n" + notes
        return prompt

    def ask(self, message):
        images, notes = self.attachments(message)
        session = self.meta("session_id")
        prompt = self.prompt_for(message, notes, resuming=bool(session))
        # 模型与思考深度（2026-11-09 James：力扣教练只用 Codex 额度；要兼顾速度和讲解质量）：
        # 默认 gpt-6.1-sol + medium，可在 config.json 用 codex_model / codex_effort 调
        args = [self.config["codex"], "exec", "--ignore-user-config", "--sandbox", "workspace-write",
                "-m", self.config.get("codex_model", "gpt-6.1-sol"),
                "-c", 'model_reasoning_effort="' + self.config.get("codex_effort", "medium") + '"',
                "-c", 'approval_policy="never"', "-c", "sandbox_workspace_write.network_access=true",
                "-C", self.config["repo"]]
        if session:
            args += ["resume", "--json"]
        else:
            args += ["--json"]
        for image in images[:5]:
            args += ["--image", str(image)]
        if session:
            args += [session]
        args += ["-"]
        result = {"text": "", "failed": False}
        process = subprocess.Popen(args, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL, text=True, env=self.env, cwd=self.config["repo"], start_new_session=True)
        self.engine_process = process

        def read_output():
            for line in process.stdout:
                try:
                    event = json.loads(line)
                except ValueError:
                    continue
                if event.get("type") == "thread.started" and event.get("thread_id"):
                    self.set_meta("session_id", event["thread_id"])
                if event.get("type") in {"error", "turn.failed"}:
                    result["failed"] = True
                item = event.get("item", {})
                if event.get("type") == "item.completed" and item.get("type") == "agent_message":
                    result["text"] = item.get("text", "")

        reader = threading.Thread(target=read_output, daemon=True)
        reader.start()
        try:
            process.stdin.write(prompt)
            process.stdin.close()
            process.wait(timeout=self.config.get("engine_timeout_seconds", 900))
        except subprocess.TimeoutExpired:
            os.killpg(process.pid, signal.SIGTERM)
            process.wait(timeout=15)
            raise RuntimeError("Coach response timed out; check remote actions before retry") from None
        finally:
            reader.join(timeout=10)
            self.engine_process = None
        if process.returncode or result["failed"] or not result["text"].strip():
            raise RuntimeError("Codex response unavailable")
        return result["text"].strip()

    def worker(self):
        # Never rerun interrupted model actions: a submission might already have succeeded.
        with self.db() as db:
            db.execute("UPDATE messages SET status='error',error='interrupted',payload=NULL WHERE status='working'")
        while not STOP.is_set():
            with self.db() as db:
                row = db.execute("SELECT * FROM messages WHERE status IN ('answered','pending') ORDER BY created_ms,rowid LIMIT 1").fetchone()
            if not row:
                self.wake.wait(2)
                self.wake.clear()
                continue
            message_id = row["id"]
            try:
                if row["status"] == "pending":
                    with self.db() as db:
                        db.execute("UPDATE messages SET status='working' WHERE id=?", (message_id,))
                    self.set_status(engine="working")
                    message = json.loads(row["payload"])
                    if not message.get("synthetic"):
                        self.acknowledge(message)
                    answer, git_request = extract_git_save(self.ask(message))
                    if git_request:
                        note = git_request["error"] if "error" in git_request else self.git_save(git_request)
                        answer = (answer + "\n\n" + note).strip()
                    answer = prepare_markdown(answer)
                    with self.db() as db:
                        db.execute("UPDATE messages SET status='answered',reply=? WHERE id=?", (answer, message_id))
                else:
                    answer = row["reply"]
                chunks = split_reply(answer)
                for index in range(row["sent_parts"], len(chunks)):
                    key = str(uuid.uuid5(uuid.NAMESPACE_URL, self.config["chat_id"] + "/" + message_id + "/" + str(index)))
                    self.send(chunks[index], key)
                    with self.db() as db:
                        db.execute("UPDATE messages SET sent_parts=? WHERE id=?", (index + 1, message_id))
                with self.db() as db:
                    db.execute("UPDATE messages SET status='done',payload=NULL,reply=NULL WHERE id=?", (message_id,))
                self.set_status(engine="idle", last_reply_at=now_iso(), last_error=None)
            except Exception as error:
                with self.db() as db:
                    current = db.execute("SELECT status FROM messages WHERE id=?", (message_id,)).fetchone()[0]
                    if current != "answered":
                        db.execute("UPDATE messages SET status='error',payload=NULL,error=? WHERE id=?", (type(error).__name__, message_id))
                self.set_status(engine="idle", last_error=str(error)[:160])
                if current != "answered":
                    try:
                        self.send("这次暂时没拿到完整回答。你可以稍后发「继续」；如果刚才在提交题目，我会先核对美国站结果再继续。",
                                  str(uuid.uuid5(uuid.NAMESPACE_URL, message_id + "/error")))
                    except Exception:
                        pass
                STOP.wait(10)

    def poll(self):
        cursor = int(self.meta("poll_cursor_ms", milliseconds(self.config["start_time"])))
        start = datetime.fromtimestamp(max(0, cursor - 60000) / 1000, timezone.utc).isoformat()
        queried_at = int(time.time() * 1000)
        data = self.cli(["im", "+chat-messages-list", "--as", "user", "--chat-id", self.config["chat_id"],
                         "--start", start, "--order", "asc", "--page-all", "--page-limit", "10",
                         "--page-size", "50", "--no-reactions", "--json"], timeout=120)
        messages = data.get("messages", [])
        for message in messages:
            self.enqueue(message, "history")
            for reply in message.get("thread_replies", []):
                self.enqueue({"chat_id": self.config["chat_id"], **reply}, "history")
        if data.get("has_more"):
            queried_at = max([milliseconds(m.get("create_time")) for m in messages] or [cursor])
        self.set_meta("poll_cursor_ms", max(cursor, queried_at))
        self.set_status(poll="ready", last_poll_at=now_iso())

    def events(self):
        selector = 'select(.chat_id == %s and .sender_id == %s and .sender_type == "user")' % (
            json.dumps(self.config["chat_id"]), json.dumps(self.config["owner_id"]))
        while not STOP.is_set():
            try:
                process = subprocess.Popen(self.cli_args(["event", "consume", "im.message.receive_v1", "--as", "bot",
                    "--timeout", "1h", "--jq", selector]), stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE, text=True, env=self.env, cwd=self.state_dir)
                self.event_process = process

                def read_errors():
                    for line in process.stderr:
                        if "[event] ready " in line:
                            self.set_status(events="ready")

                threading.Thread(target=read_errors, daemon=True).start()
                for line in process.stdout:
                    try:
                        event = json.loads(line)
                    except ValueError:
                        continue
                    self.enqueue(event, "event")
                process.wait()
                self.set_status(events="reconnecting")
            except Exception:
                self.set_status(events="unavailable; history polling active")
            finally:
                self.event_process = None
            STOP.wait(10)

    def run(self):
        lock = (self.state_dir / "bridge.lock").open("a+")
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        self.set_status(service="running", engine="idle")
        threading.Thread(target=self.worker, daemon=True).start()
        threading.Thread(target=self.events, daemon=True).start()
        while not STOP.is_set():
            try:
                self.maybe_daily_push()
            except Exception as error:
                self.set_status(daily_push_error=str(error)[:160])
            try:
                self.poll()
            except Exception as error:
                self.set_status(poll="retrying", poll_error=str(error)[:160])
            interval = self.poll_interval()
            self.set_status(poll_interval_seconds=interval)
            STOP.wait(interval)
        for process in [self.event_process, self.engine_process]:
            if process and process.poll() is None:
                if process is self.engine_process:
                    os.killpg(process.pid, signal.SIGTERM)
                else:
                    process.terminate()
        self.set_status(service="stopped")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("command", choices=["run", "status", "daily-now"])
    options = parser.parse_args()
    if options.command == "status":
        file = STATE_DIR / "status.json"
        print(file.read_text() if file.exists() else '{"service":"not started"}')
        return
    if options.command == "daily-now":
        # 手动补发一条每日推送：排进同一个队列，由运行中的服务处理
        bridge = Bridge(json.loads(CONFIG.read_text()))
        stamp = datetime.now(ZoneInfo((bridge.config.get("daily_push") or {}).get("tz", "Asia/Shanghai"))).strftime("%Y-%m-%d-%H%M")
        print("queued" if bridge.enqueue_daily_push(stamp) else "already queued")
        return
    signal.signal(signal.SIGTERM, lambda *_: STOP.set())
    signal.signal(signal.SIGINT, lambda *_: STOP.set())
    os.umask(0o077)
    Bridge(json.loads(CONFIG.read_text())).run()


if __name__ == "__main__":
    main()
