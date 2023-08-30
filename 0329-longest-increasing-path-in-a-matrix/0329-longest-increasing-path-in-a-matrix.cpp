class Solution {
    vector<int> deltaX = {0,-1,0,1};
    vector<int> deltaY = {-1,0,1,0};
    
    int isValid(int i, int j, int m, int n)
    {
        return i>=0 and i<m and j>=0 and j<n;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&vis, vector<vector<int>>& dp) {
        
        
        if(dp[i][j] != -1)
            return dp[i][j];
        vis[i][j] = 1;
        
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        for(int x=0; x < 4; x++)
        {
            int r = i + deltaX[x];
            int c = j + deltaY[x];
            
            if(isValid(r, c, m, n) and matrix[i][j] > matrix[r][c] and vis[r][c] == 0)
                res = max(res, longestIncreasingPath(matrix, r, c, vis, dp));
        }        
        
        vis[i][j] = 0;

        return dp[i][j] = res + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       
        int res=1, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        vector<vector<int>>dp(m, vector<int>(n, -1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res = max(res, longestIncreasingPath(matrix, i, j, vis, dp));
            }
        }
        return res;
    }
};