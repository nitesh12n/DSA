class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        int res=0;
        
        unordered_map<char,bool>m;
        int left=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i]) != m.end())
            {
                while(left<i and s[left] != s[i])
                {
                    m.erase(s[left]);
                    left++;
                }
                if(left<i)
                    left++;
            }
            res = max(res, i-left+1);
            m[s[i]]=true;          
        }
        return res;
    }
};