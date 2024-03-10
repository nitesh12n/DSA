class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        vis = [[0] * n for _ in range(m)]
        
        ans = set()
        
        directions = [[0, -1], [0, 1], [-1, 0], [1, 0]]
        
        def dfs(i, j, row, col, arr):
            vis[i][j] = 1
            
            arr.append((i - row, j - col))
            
            for di, dj in directions:
                ni, nj = i + di, j + dj
                
                if ni < 0 or ni > m - 1 or nj < 0 or nj > n - 1:
                    continue
                    
                if vis[ni][nj] or grid[ni][nj] != 1:
                    continue
                    
                dfs(ni, nj, row, col, arr)
        
        for i in range(m):
            for j in range(n):
                if not vis[i][j] and grid[i][j]:
                    arr = []
                    dfs(i, j, i, j, arr)
                    ans.add(tuple(arr)) 
        
        return len(ans)
