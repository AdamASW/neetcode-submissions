class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0: # odd strings can't be right.
            return False
        stack = []
        sum_open = 0
        sum_close = 0
        for el in s:
            if el in ('(','{','['):
                stack.append(el)
                sum_open += 1
            if el in (')','}',']'):
                check = None
                try:
                    check = stack.pop()
                except:
                    return False
                if check == '(':
                    if el != ')':
                        return False
                if check == '{':
                    if el != '}':
                        return False
                if check == '[':
                    if el != ']':
                        return False
                sum_close += 1
        if sum_close != sum_open:
            return False
        return True