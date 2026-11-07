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
