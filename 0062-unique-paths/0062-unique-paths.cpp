class Solution {
    int unique(int m, int n, vector<vector<int>>& dp)
    {
        if(m < 0 or n < 0)
            return 0;
        
        if(m == 0 and n==0)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int down = unique(m-1, n, dp);
        int right = unique(m, n-1, dp); 
        
        return dp[m][n] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        //return unique(m-1, n-1, dp);
        
        for(int i=0; i< m; i++)
        {
            for(int j=0; j < n; j++)
            {
                if(i == 0 or j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};