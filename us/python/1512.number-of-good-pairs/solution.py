# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/number-of-good-pairs/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/number-of-good-pairs/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682544838/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    ans += 1
        return ans

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().numIdenticalPairs(nums)
    print("\noutput:", serialize(ans, "integer"))
