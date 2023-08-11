class Solution {
    vector<int>deltaX = {0, -1, 0, 1};
    vector<int>deltaY = {-1, 0, 1, 0};
    
     bool isValid(int r, int c, int m, int n)
    {
        return r>=0 and r<m and c>=0 and c<n;
    }
   
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis, int i, int j)
    {
        int m = grid1.size(), n = grid1[0].size();
        int res = 1;    
        vis[i][j] = 1;

        for(int x=0; x <4; x++)
        {
            int r = i + deltaX[x];
            int c = j + deltaY[x];
            if(isValid(r, c, m, n) and grid2[r][c] == 1 and vis[r][c] == 0)
            {
                if(grid1[r][c] == 0)
                    res = 0;
                vis[r][c] = 1;
                if(dfs(grid1, grid2, vis, r, c) == 0)
                    res = 0;
            }
        }
    return res;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)     {
       int m = grid1.size(), n = grid1[0].size(), res=0;
       vector<vector<int>>vis(m, vector<int>(n, 0));
        
        
        for(int i=0; i< m; i++)
        {
            for(int j=0; j< n; j++)  
            {
                if(grid2[i][j] == 1 and grid1[i][j] == 1 and vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    res+=dfs(grid1, grid2, vis, i, j);
                }
            }
        }
        return res;
        
        
    }
};