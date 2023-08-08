class Solution {
    int uniquePaths(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp)
    {
        if(m==0 and n==0 and obstacleGrid[m][n] == 0)
            return 1;
        
        if(m < 0 or n < 0 or obstacleGrid[m][n] == 1)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = uniquePaths(obstacleGrid, m-1, n, dp) + 
            uniquePaths(obstacleGrid, m, n-1, dp);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return uniquePaths(obstacleGrid, m-1, n-1, dp);
    }
};