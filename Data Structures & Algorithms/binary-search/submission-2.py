import math

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1
        if len(nums) == 1 and nums[0] == target:
            return 0
        elif len(nums) == 2:
            if target == nums[0]:
                return 0
            elif target == nums[1]:
                return 1
        else:
            k = len(nums)//2
            if nums[k] == target:
                return k
            elif nums[k] < target:
                right_result = self.search(nums[k+1:], target)
                if right_result == -1:
                    return -1
                else: 
                    return k + 1 + right_result
            else:
                left_result = self.search(nums[:k], target)
                if left_result == -1:
                    return -1
                else:
                    return left_result
        return -1