class Solution:
    def isHappy(self, n: int) -> bool:
        seen = {}
        curr_num = n
        curr_digits = list(str(n))
        while curr_num not in seen:
            result = sum([int(x)**2 for x in curr_digits])
            seen[curr_num] = True
            if result == 1:
                return True
            curr_num = result
            curr_digits = list(str(curr_num))
        return False