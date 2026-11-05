"""本题的 leetgo 元数据把随机链表误认为普通链表，使用 C++ 本地入口测试。"""

import json
from pathlib import Path
import re
import subprocess
import tempfile


def main():
    folder = Path(__file__).resolve().parent
    cases = re.findall(
        r"input:\n(.*?)\noutput:\n(.*?)(?=\n\ninput:|\Z)",
        (folder / "testcases.txt").read_text(),
        re.S,
    )
    if not cases:
        raise RuntimeError("No local test cases found")
    with tempfile.TemporaryDirectory(prefix="leetcode-138-") as temporary:
        executable = Path(temporary) / "solution"
        subprocess.run(
            [
                "clang++", "-O2", "-std=c++17", "-I", str(folder.parent),
                str(folder / "solution.cpp"), "-o", str(executable),
            ],
            check=True,
        )
        for number, (input_text, expected_text) in enumerate(cases, start=1):
            result = subprocess.run(
                [str(executable)], input=input_text + "\n", text=True,
                capture_output=True, check=True, timeout=5,
            )
            actual = json.loads(result.stdout.split("output:", 1)[1])
            expected = json.loads(expected_text)
            if actual != expected:
                raise AssertionError(f"Case {number}: expected {expected}, got {actual}")
            print(f"Case {number}: Passed")
    print(f"Passed {len(cases)}/{len(cases)} cases, including deep-copy pointer checks.")


if __name__ == "__main__":
    main()
