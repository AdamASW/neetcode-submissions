class Solution:
    def climbStairs(self, n: int) -> int:
        self.M = {}
        self.M[0] = 1
        self.M[1] = 1

        try:
            return self.M[n]
        except:
            try:
                oneStep = self.M[n-1]
            except:
                oneStep = self.climbStairs(n-1)
            try:
                twoStep = self.M[n-2]
            except:
                twoStep = self.climbStairs(n-2)
            self.M[n] = oneStep + twoStep
        return self.M[n]