class Solution {
    void addPaths(int& res, int y)
    {
        res = (res+y)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>>& dp)
    {
        if(i < 0 or i==m or j<0 or j ==n)
            return maxMove >= 0;
        
        if(maxMove <= 0)
            return 0;
        
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];
        
        int res = 0;
        addPaths(res, findPaths(m, n, maxMove - 1, i-1, j, dp));
        addPaths(res, findPaths(m, n, maxMove - 1, i, j+1, dp));
        addPaths(res, findPaths(m, n, maxMove - 1, i+1, j, dp));
        addPaths(res, findPaths(m, n, maxMove - 1, i, j-1, dp));     
    
        return dp[i][j][maxMove] = res;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1,-1)));
        return findPaths(m, n, maxMove, startRow, startColumn, dp);
    }
};