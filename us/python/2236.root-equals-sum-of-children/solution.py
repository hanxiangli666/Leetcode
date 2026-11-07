# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/root-equals-sum-of-children/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/root-equals-sum-of-children/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682544753/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def checkTree(self, root: Optional[TreeNode]) -> bool:
        return root.val == root.left.val + root.right.val

# @lc code=end

if __name__ == "__main__":
    root: TreeNode = deserialize("TreeNode", read_line())
    ans = Solution().checkTree(root)
    print("\noutput:", serialize(ans, "boolean"))
