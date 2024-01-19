class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        
        
        n = len(matrix)
        res = float('inf')
        dp = {}
        def minPathSum(r, c):
            
            if c < 0 or c >= n:
                return float('inf')
            
            if r == n :
                return 0
            if (r,c) in dp:
                return dp[r,c]    
            
            dp[r, c] =  matrix[r][c]  + min(minPathSum(r + 1, c - 1), minPathSum(r + 1, c), minPathSum(r + 1, c + 1))
            return dp[r,c]
        
        for col in range(0, n):
            res = min(res, minPathSum(0, col))
            
        return res
            
        
        
        
        