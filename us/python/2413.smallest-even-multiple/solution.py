# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/smallest-even-multiple/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/smallest-even-multiple/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682544685/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        # Check if n is even
        if n % 2 == 0:
            # Even number: smallest even multiple is itself
            return n
        # Odd number: smallest even multiple is n * 2
        return n * 2

# @lc code=end

if __name__ == "__main__":
    n: int = deserialize("int", read_line())
    ans = Solution().smallestEvenMultiple(n)
    print("\noutput:", serialize(ans, "integer"))
