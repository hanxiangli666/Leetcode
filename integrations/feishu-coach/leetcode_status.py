"""Read US problem status without returning credentials or submission code."""
from pathlib import Path
import json
import re
import sys
import urllib.request


def statuses(slugs):
    if not slugs or len(slugs) > 10 or any(not re.fullmatch(r"[a-z0-9-]+", s) for s in slugs):
        raise ValueError("Supply 1–10 problem slugs")
    root = Path(__file__).resolve().parents[2]
    values = {}
    for line in (root / "us/.env").read_text().splitlines():
        if "=" in line and not line.lstrip().startswith("#"):
            key, value = line.split("=", 1)
            values[key.strip()] = value.strip().strip("\"'")
    cookies = {"LEETCODE_SESSION": values["LEETCODE_SESSION"],
               "csrftoken": values["LEETCODE_CSRFTOKEN"]}
    if values.get("LEETCODE_CFCLEARANCE"):
        cookies["cf_clearance"] = values["LEETCODE_CFCLEARANCE"]
    query = "query { " + " ".join(
        'q%d:question(titleSlug:%s){questionFrontendId title titleSlug difficulty status}'
        % (i, json.dumps(slug)) for i, slug in enumerate(slugs)) + " }"
    request = urllib.request.Request("https://leetcode.com/graphql/",
        data=json.dumps({"query": query}).encode(), headers={
            "Content-Type": "application/json", "Referer": "https://leetcode.com/",
            "User-Agent": "Mozilla/5.0", "Cookie": "; ".join(k + "=" + v for k, v in cookies.items()),
            "x-csrftoken": cookies["csrftoken"]})
    with urllib.request.urlopen(request, timeout=30) as response:
        result = json.load(response)
    if result.get("errors") or "data" not in result:
        raise RuntimeError("LeetCode did not return problem statuses")
    return [result["data"]["q" + str(i)] for i in range(len(slugs))]


if __name__ == "__main__":
    try:
        print(json.dumps({"ok": True, "questions": statuses(sys.argv[1:])}, ensure_ascii=False))
    except Exception as error:
        # Never echo request headers, auth values or raw service responses.
        print(json.dumps({"ok": False, "error": type(error).__name__}))
        sys.exit(1)
