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
    bool camelMatch(string word, string pattern, int i, int j)
    {
       if(i == word.size() and j == pattern.size())
           return true;
       if(i == word.size())
           return false;
        if(j == pattern.size())
            return isRemainingValid(word, i);
        
        bool res = false;
        
        if(word[i] == pattern[j])
            res = camelMatch(word, pattern, i+1, j+1);
        else if(word[i] == tolower(word[i]))
            res =  camelMatch(word, pattern, i+1, j);
        
     return res;
    }
    
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool>res;
        
        for(auto query :queries)
            res.push_back(camelMatch(query, pattern, 0, 0));

    return res;
    }
};