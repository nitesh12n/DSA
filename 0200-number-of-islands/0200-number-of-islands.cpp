class Solution {
public:
    bool isValid(int m, int n, int r, int c)
    {
        return r >=0 && r <m && c >=0 && c<n;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col)
    {
    
     vis[row][col] = 1;   
     int rowDelta[] = {-1, 0, 1, 0};
     int colDelta[] = {0, -1, 0, 1};
     int m = grid.size();
     int n = grid[0].size();  
        
     for(int i=0;i<4;i++)
     {
         int r = row + rowDelta[i];
         int c = col + colDelta[i];
         if(isValid(m, n, r, c) && grid[r][c] == '1' && vis[r][c]==0)
            dfs(grid, vis, r, c);
     }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>>vis(m, vector<int>(n, 0));
    int res = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j] == 0 && grid[i][j] == '1')
            {
                res++;
                dfs(grid, vis, i, j);
            }
        }
    }
    return res;
    }
};