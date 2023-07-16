class Solution {
private:    
    void longest(string s, int l, int r, string& res)
    {
        while(l>=0 and r <s.size() and s[l]==s[r])
        {
            if(res.size() < r-l+1)
                res = s.substr(l, r-l+1);
            l--;
            r++;
        }
    }
    
public:
    string longestPalindrome(string s) {
     
        string res;        
        for(int i=0;i<s.size();i++)
        { 
          longest(s, i, i, res);
          longest(s, i, i+1, res);        
        }
        return res;
    }
};