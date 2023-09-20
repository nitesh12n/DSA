class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        
        int j = 0;
        for(int i = 0; i <words.size(); i++)
        {
            if(words[i][0] != s[j++])
                return false;
        }
    return j == s.size();
    }
};