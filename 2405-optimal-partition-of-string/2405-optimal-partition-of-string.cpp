class Solution {
    
public:
    int partitionString(string s) {
        
        
        unordered_map<char, bool>m;
        
        int i=0, res=1;
        while(i < s.size())
        {
            if(m.find(s[i]) != m.end())
            {
                res++;
                m.clear();
                
            }
            m[s[i]] = true;
        i++;
        }
        return res;
        
    }
};