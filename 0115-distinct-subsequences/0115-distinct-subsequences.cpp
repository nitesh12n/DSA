class Solution {
    long long numDistinct(string& s, string& t, int i, int j, vector<vector<long long>>& dp) {
        
        if(j == t.size())
            return 1;
        if(i == s.size())
            return 0;
           
        if(dp[i][j] != -1)
            return dp[i][j] > INT_MAX ? -1 : dp[i][j]; 
        
        if(s[i] != t[j])
            return dp[i][j] = numDistinct(s, t, i+1, j, dp);
        
        return dp[i][j] = numDistinct(s, t, i+1, j+1, dp) + numDistinct(s, t, i+1, j, dp);
        
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>>dp(s.size(), vector<long long>(t.size(), -1));
        long long res =  numDistinct(s, t, 0, 0, dp);
        if(res > INT_MAX)
            return -1;
        return res;
    }
};