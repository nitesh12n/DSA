class Solution {
private: 
    bool isValid(string s1, string s2, unordered_map<char,int>&m)
    {
        
        int size = min(s1.size(), s2.size());
        int i=0;
        while(i<size and s1[i]==s2[i])
            i++;
        
        if(i<size)
            return m[s1[i]] < m[s2[i]];
        if(i<s1.size())
            return false;
            
     return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>m;
        
        for(int i=0;i<order.size();i++)
            m[order[i]] = i;
        
        for(int i=1;i<words.size();i++)
        {
            if(!isValid(words[i-1], words[i], m))
                return false;
        }
    return true;
    }
};