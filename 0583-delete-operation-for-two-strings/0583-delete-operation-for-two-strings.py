class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[-1] * n for _ in range(m)]
        
        def lcs(i, j):
            if i == m:
                return 0
            
            if j == n:
                return 0
            
            if dp[i][j] != -1:
                return dp[i][j]
            
            if word1[i] == word2[j]:
                dp[i][j] = 1 + lcs(i + 1, j + 1)
                return dp[i][j]
            
            dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1))
            return dp[i][j]
        
        lenLCS = lcs(0, 0)
        
        print(lenLCS)
        
        return (m - lenLCS + n - lenLCS)
    