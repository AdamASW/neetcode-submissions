class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        Hist = {}
        for i in nums:
            try:
                if Hist[i] == 'True':
                    return True
            except:
                Hist[i] = 'True'
        return False