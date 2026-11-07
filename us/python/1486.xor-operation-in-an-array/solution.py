# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/xor-operation-in-an-array/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/xor-operation-in-an-array/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682544796/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        ans = 0
        for i in range(n):
            ans ^= (start + i * 2)
        return ans

# @lc code=end

if __name__ == "__main__":
    n: int = deserialize("int", read_line())
    start: int = deserialize("int", read_line())
    ans = Solution().xorOperation(n, start)
    print("\noutput:", serialize(ans, "integer"))
