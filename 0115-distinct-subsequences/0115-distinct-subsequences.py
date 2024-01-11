class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        
        dp = {}
        M, N = len(s), len(t)
        
        def numDistinct(i, j):
            
            if j == N:
                return 1
            if i == M or M - i < N - j:
                return 0
            
            if (i, j) in dp:
                return dp[i, j]
            
            res = numDistinct(i + 1, j)
            
            if s[i] == t[j]:
                res+= numDistinct(i + 1, j + 1)
                 
            dp[i, j] = res
            return res
        
        return numDistinct(0, 0)