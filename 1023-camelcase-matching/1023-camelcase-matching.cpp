class Solution {
    bool isRemainingValid(string word, int i)
    {
        while(i < word.size())
        {
            if(word[i] != tolower(word[i]))
                return false;
            i++;
        }
    return true;
    }
    bool camelMatch(string word, string pattern, int i, int j, vector<vector<int>>& dp)
    {
       if(i == word.size() and j == pattern.size())
           return true;
       if(i == word.size())
           return false;
        if(j == pattern.size())
            return isRemainingValid(word, i);
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool res = false;
        
        if(word[i] == pattern[j])
            res = camelMatch(word, pattern, i + 1, j + 1, dp);
        else if(word[i] == tolower(word[i]))
            res =  camelMatch(word, pattern, i + 1, j, dp);
        
     return dp[i][j] = res;
    }
    
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool>res;
        for(auto query :queries)
        {
            vector<vector<int>>dp(query.size(), vector<int>(pattern.size(), -1));
            res.push_back(camelMatch(query, pattern, 0, 0, dp));
        }

    return res;
    }
};