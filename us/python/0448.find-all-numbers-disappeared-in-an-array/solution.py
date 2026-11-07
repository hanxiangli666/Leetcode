# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682959906/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        set_nums = set(nums)
        ret = []
        for i in range(1, len(nums)+1):
            if i not in set_nums:
                ret.append(i)
        return ret

# @lc code=end

if __name__ == "__main__":
    nums: List[int] = deserialize("List[int]", read_line())
    ans = Solution().findDisappearedNumbers(nums)
    print("\noutput:", serialize(ans, "integer[]"))
