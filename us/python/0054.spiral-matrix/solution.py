# Created by James at 2026/11/07 10:47
# leetgo: 1.5.2
# https://leetcode.com/problems/spiral-matrix/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/spiral-matrix/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/683333603/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ret = []
        while matrix:
            #1) add first row/list of matrix
            ret += (matrix.pop(0))
            #2) add last element of each remaining row/list of matrix
            if matrix and matrix[0]:
                for row in matrix:
                    ret.append(row.pop())
            #3) add last row/list of matrix in reverse order
            if matrix:
                ret += (matrix.pop()[::-1])
            #4) add first element of each remaining row/list of matrix in reverse order
            if matrix and matrix[0]:
                for row in matrix[::-1]:
                    ret.append(row.pop(0))
        return ret

# @lc code=end

if __name__ == "__main__":
    matrix: List[List[int]] = deserialize("List[List[int]]", read_line())
    ans = Solution().spiralOrder(matrix)
    print("\noutput:", serialize(ans, "integer[]"))
