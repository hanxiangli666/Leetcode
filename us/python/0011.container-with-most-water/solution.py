# Created by James at 2026/11/07 10:47
# leetgo: 1.5.2
# https://leetcode.com/problems/container-with-most-water/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/container-with-most-water/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682782673/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        left = 0
        right = len(height) - 1
        while left < right:
            area = min(height[left], height[right]) * (right - left)
            ans = max(ans, area)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return ans

# @lc code=end

if __name__ == "__main__":
    height: List[int] = deserialize("List[int]", read_line())
    ans = Solution().maxArea(height)
    print("\noutput:", serialize(ans, "integer"))
