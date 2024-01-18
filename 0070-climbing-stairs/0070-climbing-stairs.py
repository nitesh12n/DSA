class Solution:
    def climbStairs(self, n: int) -> int:
        
        dp = {}
        
        def climb(n):
            
            if n <= 1:
                return 1
            if n in dp.keys():
                return dp[n]
            
            dp[n] = climb(n - 1) + climb(n - 2)
            return dp[n]
        return climb(n)
        