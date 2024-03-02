class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        
        ans = 0
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        dp = {}
        def recurse(i, j):
                
            if (i, j) in dp:
                return dp[i,j]
            
            nodes = 1

            for di, dj in directions:
                ni, nj = i + di, j + dj
                
                if ni < 0 or ni > m - 1 or nj < 0 or nj > n - 1 or matrix[i][j] <= matrix[ni][nj]:
                    continue
                    
                nodes = max(nodes, 1 + recurse(ni, nj))   
                
            dp[i,j] = nodes
            return nodes

        
        for i in range(m):
            for j in range(n):
                ans = max(ans, recurse(i, j))
        
        return ans