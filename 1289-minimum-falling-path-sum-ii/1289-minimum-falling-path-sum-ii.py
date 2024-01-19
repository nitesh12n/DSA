class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        
        
        n = len(grid)
        res = float('inf')
        dp = {}
        def minPathSum(r, c):
            
            if c < 0 or c >= n:
                return float('inf')
            
            if r == n - 1:
                return grid[r][c]
            
            if (r,c) in dp:
                return dp[r,c]    
            
            #dp[r, c] =  grid[r][c]  + min(minPathSum(r + 1, c - 1), minPathSum(r + 1, c + 1))
            dp[r, c] = grid[r][c] + min(
                minPathSum(r + 1, nc) for nc in range(n) if nc != c)
            
            
            return dp[r, c]
        
        for col in range(0, n):
            res = min(res, minPathSum(0, col))
            
        return res