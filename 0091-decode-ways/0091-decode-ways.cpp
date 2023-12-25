class Solution {

private: 
    char decode(string s)
    {
        if(s[0]=='0')
            return '\0';
        
        int num = stoi(s);
        if(num > 0 and num <= 26)
            return 'A'+num-1;
        return '\0';
    }
    int numDecodings(string s, int index, vector<int>& dp)
    {
        if(index == s.size())
            return 1;

        if(dp[index] != -1)
            return dp[index];
        char ch = decode(s.substr(index,1));
        int ans = 0;
        if(ch != '\0')
            ans= numDecodings(s, index + 1, dp);
        if(index+1 <s.size())
        {
            
            ch = decode(s.substr(index,2));
            if(ch != '\0')
                ans+= numDecodings(s, index + 2, dp);
        }  
        return dp[index]= ans;
    }
public:
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return numDecodings(s, 0, dp);
    }
};