
class Solution {
    int MAX = INT_MAX-100;
    int minExtraChar(string s, int index, vector<string>& dictionary, vector<int>& dp)
    {        
        if(index == s.size())
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int res = MAX;
        for(string word : dictionary)
        {
            int len = word.size();
            string str = s.substr(index, len);
            if(word == str)
                res = min(res, minExtraChar(s, index + len, dictionary, dp));
        }
        
        return dp[index] = min(res, 1 + minExtraChar(s, index + 1, dictionary, dp));
    }
    
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int>dp(s.size(), -1);
        return minExtraChar(s, 0, dictionary, dp);
    }
};