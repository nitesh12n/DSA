class Solution {
    
    bool wordBreak(string s, int index, vector<string>& wordDict, vector<int>&dp) 
    {
        if(index == s.size())
            return true;
        
        if(dp[index] != -1)
            return dp[index];
        
        string str = s.substr(index);
        bool res = false;
        for(string word : wordDict)
        {
            int len = word.size();   
            string str = s.substr(index, len);
            
            if(word == str)
            {
                res = res || wordBreak(s, index + len, wordDict, dp);
            }
        }
    return dp[index] = res;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(), -1);
        return wordBreak(s, 0, wordDict, dp);
    }
};