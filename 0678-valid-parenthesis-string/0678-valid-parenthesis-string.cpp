class Solution {
    
    bool checkValidString(string s, int index, int open, int close, unordered_map<string, bool>& dp)
    {
        if(index == s.size())
            return open == close;
        
        string key = to_string(index) + to_string(open) + to_string(close);
        
        if(dp.find(key) != dp.end())
            return dp[key];
        
        if(s[index] == '(')
            return dp[key] = checkValidString(s, index + 1, open + 1, close, dp);
        else if(s[index] == ')')
            return dp[key] = open > close and checkValidString(s, index + 1, open, close + 1, dp);
        else 
            return dp[key] = (checkValidString(s, index + 1, open + 1, close, dp)
                or (open > close and checkValidString(s, index + 1, open, close + 1, dp)) 
                or checkValidString(s, index + 1, open, close, dp));
    }
    
    
public:
    bool checkValidString(string s) {
        unordered_map<string, bool>dp;
        return checkValidString(s, 0, 0, 0, dp);
        
        
        
    }
};