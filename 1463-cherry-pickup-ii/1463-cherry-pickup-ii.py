class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        
        rows, cols = len(grid), len(grid[0])
        dp = {}
        def pickup(row, col1, col2):
            
            if col1 < 0 or col1 == cols or col2 < 0 or col2 == cols:
                return float(-inf)
            
            res = grid[row][col1]
            
            if col1 != col2:
                res+= grid[row][col2]
            
            if row == rows - 1:
                return res
            
            if (row, col1, col2) in dp:
                return dp[row, col1, col2]
            
            ans = 0
            for i in range(-1, 2):
                for j in range(-1,2):
                    ans =  max(ans, pickup(row + 1, col1 + i, col2 + j))
            res+= ans
            dp[row, col1, col2] = res    
            return res
        
        return pickup(0, 0, cols - 1)
            
            
            
        