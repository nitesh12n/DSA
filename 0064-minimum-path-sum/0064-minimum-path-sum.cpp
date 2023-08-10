class Solution {
    
    int minPathSum(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp)
    {
        if(i<0 or j<0)
            return 1e7;
        
        if(i==0 and j==0)
            return grid[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        //top
        int top = minPathSum(grid, i-1, j, dp);
        //left
        int left = minPathSum(grid, i, j-1, dp);
        
        return dp[i][j] = min(top, left) + grid[i][j];

    }
        
public:
    int minPathSum(vector<vector<int>>& grid) {
     
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return minPathSum(grid, m-1, n-1, dp);
    }
};