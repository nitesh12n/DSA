class Solution {
    
    vector<int> deltaX = {0,-1,0,1};
    vector<int> deltaY = {-1,0,1,0};
    
    int isValid(int i, int j, int m, int n)
    {
        return i>=0 and i<m and j>=0 and j<n;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis)
    {
        vis[i][j] = 1;
        int m = grid.size(), n = grid[0].size();
        
        for(int x=0; x < 4; x++)
        {
            int r = i + deltaX[x];
            int c = j + deltaY[x];
            
            if(isValid(r, c, m, n) and grid[r][c] == '1' and vis[r][c]==0)
                dfs(grid, r, c, vis);            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int res=0, m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' and vis[i][j]==0)
                {
                    res++;
                    dfs(grid, i, j, vis);
                }      
            }
        }
        return res;
    }
};