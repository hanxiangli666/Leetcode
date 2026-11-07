# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/minimum-time-visiting-all-points/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/minimum-time-visiting-all-points/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/683333465/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        res = 0
        x1, y1 = points.pop()
        while points:
            x2, y2 = points.pop()
            res += max(abs(x2 - x1), abs(y2 - y1))
            x1, y1 = x2, y2
        return res

# @lc code=end

if __name__ == "__main__":
    points: List[List[int]] = deserialize("List[List[int]]", read_line())
    ans = Solution().minTimeToVisitAllPoints(points)
    print("\noutput:", serialize(ans, "integer"))
