class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        mod = 1e9 + 7
        dp = {}
        def paths(i, j, move):
                        
            if (i < 0 or i == m or j < 0 or j == n):
                return 1
            
            if move <= 0:
                return 0
            res = 0
            
            if (i, j, move) in dp:
                return dp[i, j, move]
            
            for (x, y) in directions:
                res+= paths(i + x, j + y, move - 1)
                res%=mod
            dp[i, j, move] = res    
            return res
        
        return paths(startRow, startColumn, maxMove)
            
            
            
        