class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(el for el in s.lower() if el.isalnum())
        x = 0
        y = len(s) - 1
        while x < y:
            if s[x] != s[y]:
                return False
            x += 1
            y -= 1
        return True