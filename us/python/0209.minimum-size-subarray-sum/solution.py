# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/minimum-size-subarray-sum/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/minimum-size-subarray-sum/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/683384687/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n + 1
        s = 0
        left = 0
        for right, x in enumerate(nums):
            s += x
            while s - nums[left] >= target:
                s -= nums[left]
                left += 1
            if s >= target:
                ans = min(ans, right-left+1)
        return ans if ans <= n else 0

# @lc code=end

if __name__ == "__main__":
    target: int = deserialize("int", read_line())
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().minSubArrayLen(target, nums)
    print("\noutput:", serialize(ans, "integer"))
