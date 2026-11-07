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
