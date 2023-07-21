class Solution {
private: 
    string getNextWord(string s, int& index)
    {
        string word = "";
        while(s[index] == ' ' and index < s.size())
            index++;
        
        while(s[index]!=' ' and index < s.size())
        {
            word = word+s[index];
            index++;
        }
        return word;
    }
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string>m;
        int i=0,j=0;
        for(i=0; i<pattern.size() and j<s.size();i++)
        {
            string word = getNextWord(s, j);
            
            if(m.find(pattern[i]) != m.end())
            {
                if(m[pattern[i]] != word)
                    return false;
            }
            else
            {
                for(auto a : m)
                {
                    if(a.second == word and a.first != pattern[i])
                        return false;
                }
                
                m[pattern[i]] = word;
            }
        }
        return i==pattern.size() and j==s.size();
    }
};