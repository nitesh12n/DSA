class Solution {
    string getNextWord(string s, int& i)
    {
        string res;
        
        while(i < s.size() and s[i] != ' ')
            res+=s[i++];
        i++;
        return res;
    }
    
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        
        unordered_map<string, int>m;
        int i=0;
        while(i < s1.size())
            m[getNextWord(s1, i)]++;
        i = 0;
        while(i < s2.size())
            m[getNextWord(s2, i)]++;
        
        vector<string>res;
        for(auto it : m)
            if(it.second == 1)
                res.push_back(it.first);
        
        return res;
        
    }
};