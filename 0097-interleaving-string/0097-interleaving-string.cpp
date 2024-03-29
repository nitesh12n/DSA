class Solution {
    bool isInterleave(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<int>>& dp)
    {
        if(i == s1.size() and j == s2.size() and k == s3.size())
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool res = false;
        if(i < s1.size() and s1[i] == s3[k])
            res =  isInterleave(s1, s2, s3, i + 1, j, k + 1, dp);
        if(j < s2.size() and s2[j] == s3[k])
            res |= isInterleave(s1, s2, s3, i, j + 1, k + 1, dp);
        
    return dp[i][j] = res;
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.size() + s2.size() != s3.size())
            return false;
        //vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        //return isInterleave(s1, s2, s3, 0, 0, 0, dp);
        
        vector<vector<bool>>dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));

        for(int i=0; i<= s1.size(); i++)
        {
            for(int j = 0; j <= s2.size(); j++)
            {
                int k = i + j - 1;
                
                if(i==0 and j==0)
                    dp[i][j] = true;
                else
                {
                    if(i > 0 and s1[i-1] == s3[k])
                        dp[i][j] = dp[i-1][j];
                    if (j > 0 and s2[j-1] == s3[k])
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                }
                
            }
        }
    return dp[s1.size()][s2.size()];
    }
};