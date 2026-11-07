# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/add-two-integers/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/add-two-integers/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682544531/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def sum(self, num1: int, num2: int) -> int:
        return num1 + num2

# @lc code=end

if __name__ == "__main__":
    num1: int = deserialize("int", read_line())
    num2: int = deserialize("int", read_line())
    ans = Solution().sum(num1, num2)
    print("\noutput:", serialize(ans, "integer"))
