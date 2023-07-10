class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int baseRow, int baseCol, vector<pair<int, int>>& cells)
    {
     vis[row][col] = 1;   
     int rowDelta[] = {-1, 0, 1, 0};
     int colDelta[] = {0, -1, 0, 1};
     int m = grid.size();
     int n = grid[0].size();  
        
     cells.push_back({row-baseRow, col-baseCol});   
        
     for(int i=0;i<4;i++)
     {
         int r = row + rowDelta[i];
         int c = col + colDelta[i];
         if(r >=0 && r <m && c >=0 && c<n&& grid[r][c] == 1 && vis[r][c]==0)
            dfs(grid, vis, r, c, baseRow, baseCol, cells);
     }
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        
       int m = grid.size();
       int n = grid[0].size(); 
        
       vector<vector<int>> vis(m, vector<int>(n, 0));
       vector<pair<int, int>>cells;
       set<vector<pair<int,int>>>s; 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]== 1 && vis[i][j] == 0)
                {
                    dfs(grid, vis, i, j, i, j, cells);
                    s.insert(cells);
                    cells.clear();
                }
            }
        }
        return s.size();
    }
};