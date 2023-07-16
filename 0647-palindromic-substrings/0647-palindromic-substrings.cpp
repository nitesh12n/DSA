class Solution {
public:
    void palindrome(string s, int l, int r, int& res)
    {
        while(l>=0 and r <s.size() and s[l]==s[r])
        {
            res++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        
        int res=0;        
        for(int i=0;i<s.size();i++)
        { 
          palindrome(s, i, i, res);
          palindrome(s, i, i+1, res);        
        }
        return res; 
    }
};