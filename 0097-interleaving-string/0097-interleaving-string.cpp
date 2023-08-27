class Solution {
    bool isInterleave(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<vector<int>>>& dp)
    {
        if(i == s1.size() and j == s2.size() and k == s3.size())
            return true;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        bool res = false;
        if(i < s1.size() and s1[i] == s3[k])
            res =  isInterleave(s1, s2, s3, i + 1, j, k + 1, dp);
        if(j < s2.size() and s2[j] == s3[k])
            res |= isInterleave(s1, s2, s3, i, j + 1, k + 1, dp);
        
    return dp[i][j][k] = res;
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<vector<int>>>dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
        return isInterleave(s1, s2, s3, 0, 0, 0, dp);
    }
};