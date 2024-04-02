class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char>m1;
        unordered_map<char,char>m2;
        if(s.size() != t.size())
            return false;
        
        for(int i=0;i<s.size();i++)
        {
            if(m1.find(s[i]) == m2.end() and m2.find(t[i]) == m1.end())
               {
                   m1[s[i]] = t[i];
                   m2[t[i]] = s[i];
               }
            else if(m1[s[i]] != t[i] || m2[t[i]] != s[i])
                return false;
        }
        return true;
    }
};