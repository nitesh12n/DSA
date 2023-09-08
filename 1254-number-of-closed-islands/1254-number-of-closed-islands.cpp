class Solution {
    vector<int> dx {0, 1, 0, -1};
    vector<int> dy {-1, 0, 1, 0};
    
    bool dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        
        
        if(i < 0 or j < 0 or i == m or j == n)
            return false;
        
        if(grid[i][j] == 1 or vis[i][j] == 1)
            return true;
        
        vis[i][j] = 1;  
        bool res = true;
        for (int x = 0; x < 4; x++) 
        {
            int r = i + dx[x];
            int c = j + dy[x];
            if(!dfs(r, c, m, n, grid, vis))
                res = false;
        }
    return res;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(m, vector<int>(n)); 
        
         for (int i = 0; i < m; i++) 
         {
            for (int j = 0; j < n; j++) 
            {
                if(grid[i][j] == 0 and vis[i][j] == 0 and dfs(i, j, m, n, grid, vis))
                    res++;
            }
         }
    return res;
    }
};