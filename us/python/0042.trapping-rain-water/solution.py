# Created by James at 2026/11/07 10:47
# leetgo: 1.5.2
# https://leetcode.com/problems/trapping-rain-water/

from typing import *
from leetgo_py import *

# @lc code=begin

# 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
# 原题：https://leetcode.cn/problems/trapping-rain-water/
# 原 Accepted 提交：https://leetcode.cn/submissions/detail/683378276/
# 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

from typing import List, Optional, Dict, Tuple, Set

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        pre_max = [0] * n
        pre_max[0] = height[0]
        for i in range(1, n):
            pre_max[i] = max(pre_max[i - 1], height[i])
        suf_max = [0] * n
        suf_max[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            suf_max[i] = max(suf_max[i + 1], height[i])
        ans = 0
        for h, pre, suf in zip(height, pre_max, suf_max):
            ans += min(pre, suf) - h
        return ans
        

if __name__ == '__main__':
    s = Solution()
    # 测试用例:
    testCase = [4,2,0,3,2,5]
    result = s.trap(testCase)
    print(result)

# @lc code=end

if __name__ == "__main__":
    height: List[int] = deserialize("List[int]", read_line())
    ans = Solution().trap(height)
    print("\noutput:", serialize(ans, "integer"))
