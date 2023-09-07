class Solution {
    int minimumTotal(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>&dp)
    {
        if(i==0 and j==0)
            return triangle[i][j];
        
        if(i < 0 or j < 0 or i < j)
            return INT_MAX;
        
       if(dp[i][j] != -1)
           return dp[i][j];
       int topLeft = minimumTotal(triangle, i-1, j-1, dp);
       int top = minimumTotal(triangle, i-1, j, dp);
        
       if(topLeft == INT_MAX and top == INT_MAX)
           return dp[i][j] = INT_MAX;
        
        return dp[i][j] = min(top, topLeft) + triangle[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size(), res = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int j = 0; j < n;j++)
            res = min(res, minimumTotal(triangle, n - 1, j, dp));

        return res;
    }
};