class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # hash_set = set()
        # for n in nums:
        #     if n in hash_set:
        #         hash_set.remove(n)
        #     else:
        #         hash_set.add(n)
        # return hash_set.pop()
        nums = sorted(nums)
        hash_bits = nums[0]
        for i in range(1, len(nums)):
            hash_bits = hash_bits ^ nums[i]
        return hash_bits