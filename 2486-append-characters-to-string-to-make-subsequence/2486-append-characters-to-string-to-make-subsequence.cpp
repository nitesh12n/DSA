class Solution {
public:
    int appendCharacters(string s, string t) {
        
        
        int j = 0;
        for(int i = 0; i < t.size(); i++)         
        {
            
            while(j < s.size() and t[i] != s[j])
                j++;
            
            if(j == s.size())
                return t.size() - i;
            else
                j++;
        }
        return 0;
    }
};