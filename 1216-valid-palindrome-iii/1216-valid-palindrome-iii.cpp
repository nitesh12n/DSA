class Solution {
    
    int lcs(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 or j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = lcs(s1, s2, i-1, j-1, dp) + 1;
        
        return dp[i][j] = max(lcs(s1, s2, i, j-1, dp), lcs(s1, s2, i-1, j, dp));

    }
    
public:
    bool isValidPalindrome(string s, int k) {
        
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        string s2 = s; 
        reverse(s2.begin(), s2.end());
        if( n - lcs(s, s2, n - 1, n - 1, dp) <= k)
            return true;
        
        return false;
            
        
    }
};