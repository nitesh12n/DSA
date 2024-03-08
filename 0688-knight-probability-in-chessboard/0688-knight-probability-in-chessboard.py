class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        
        dirs = [(1, -2), (-1,-2), (-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1)]
        dp = {}
        def ways(r, c, curr):

            if r < 0 or c < 0 or r >= n or c >= n:
                
                return 0           
            
            if curr == k:
                return 1
            
            if (r, c, curr) in dp:
                return dp[r, c, curr]
            
            res = 0    
            for x, y in dirs:
                
                newR, newC = r + x, c + y
                res+= ways(newR, newC, curr + 1)
            dp[r,c,curr] = res/8.0
            return dp[r,c,curr]
                
        return ways(row, column, 0)
            
            
            
        