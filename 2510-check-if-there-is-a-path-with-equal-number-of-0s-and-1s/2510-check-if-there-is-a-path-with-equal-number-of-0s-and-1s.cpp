class Solution {
    
    bool hasPath(vector<vector<int>>& grid, int i, int j, int m, int n, int count, vector<vector<vector<int>>>& dp)
    {
        
          if(i == m || j == n) 
            return false;    

        count+= grid[i][j] == 0 ? -1 : 1;
        
        if( i == m - 1 && j == n - 1)
            return count == 0;
        
        if(dp[i][j][count + m + n] != -1)
            return dp[i][j][count + m + n];
        
        return dp[i][j][count + m + n] = hasPath(grid, i + 1, j, m, n, count, dp) || hasPath(grid, i, j + 1, m, n, count, dp); 
    }
    
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2*(m + n), -1)));

        return hasPath(grid, 0, 0, m, n, 0, dp);
    }
};