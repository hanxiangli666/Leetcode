# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/to-lower-case/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/to-lower-case/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682544990/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def toLowerCase(self, s: str) -> str:
        return s.lower()

# @lc code=end

if __name__ == "__main__":
    s: str = deserialize("str", read_line())
    ans = Solution().toLowerCase(s)
    print("\noutput:", serialize(ans, "string"))
