"""Check cycle construction and the exact returned entry node (leetgo's ListNode metadata cannot express an index)."""
from pathlib import Path
import json
import subprocess
import tempfile

folder = Path(__file__).resolve().parent
cases = [([3, 2, 0, -4], 1), ([1, 2], 0), ([1], -1), ([], -1), ([7], 0)]
with tempfile.TemporaryDirectory(prefix="leetcode-142-") as directory:
    executable = Path(directory) / "solution"
    subprocess.run(["clang++", "-O2", "-std=c++17", "-I", str(folder.parent),
                    str(folder / "solution.cpp"), "-o", str(executable)], check=True)
    for index, (values, position) in enumerate(cases, 1):
        result = subprocess.run([str(executable)], input=json.dumps(values) + "\n" + str(position) + "\n",
                                text=True, capture_output=True, timeout=5, check=True)
        actual = int(result.stdout.split("output:", 1)[1].strip())
        assert actual == position, (values, position, actual)
        print(f"Case {index}: Passed")
