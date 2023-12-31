class Solution {
    
    vector<int>deltaX = {1, -1, 0, 0};
    vector<int>deltaY = {0, 0, 1, -1};
    bool isValid(int i, int j, int m, int n)
    {
        return i >= 0 and i < m and j >= 0 and j < n;
    }
    bool dfs(vector<vector<char>>& grid, pair<int,int>src, int i , int j, vector<vector<int>>& vis, char lastChar)
    {      
        vis[i][j] = 1;
        for(int x = 0; x < 4; x++)
        {
            int newX = i + deltaX[x];
            int newY = j + deltaY[x];
            
            if(isValid(newX, newY, grid.size(), grid[0].size()))
            {
                if(!(newX == src.first and newY == src.second))
                {
                    if(grid[newX][newY] == lastChar)
                    {
                        if(vis[newX][newY])
                            return true;
                        if(dfs(grid, {i, j}, newX, newY, vis, lastChar))
                            return true;                 
                    }
                }
                 
            }
        }
        return false;
    }
    
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 0 and dfs(grid, {-1, -1}, i, j, vis, grid[i][j]))
                    return true;
            }
        }
        return false;
    }
};