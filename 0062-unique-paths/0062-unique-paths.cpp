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
        //vector<vector<int>>dp(m, vector<int>(n, -1));
        //return unique(m-1, n-1, dp);
        vector<vector<int>>dp(2, vector<int>(n, 1));
        for(int i=1; i< m; i++)
        {
            for(int j=1; j < n; j++)
            {
                    dp[i%2][j] = dp[(i-1)%2][j] + dp[i%2][j-1];
            }
        }
        return dp[(m-1)%2][n-1];
    }
};