# Created by James at 2026/11/07 10:48
# leetgo: 1.5.2
# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/682779588/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        
        while left < right: # <--- 2. 更规范的循环条件
            s = numbers[left] + numbers[right]
            
            if s == target:
                # 找到答案，直接返回
                # LeetCode要求返回从1开始的索引，所以需要 + 1
                return [left + 1, right + 1] 
            
            elif s > target:
                # 和太大，将右指针左移
                right -= 1 
            else: # s < target
                # 和太小，将左指针右移
                left += 1
        
        # 如果题目保证一定有解，可以省略下面的代码，但如果没保证，则需要处理无解情况
        return []

# @lc code=end

if __name__ == "__main__":
    numbers: List[int] = deserialize("List[int]", read_line())
    target: int = deserialize("int", read_line())
    ans = Solution().twoSum(numbers, target)
    print("\noutput:", serialize(ans, "integer[]"))
