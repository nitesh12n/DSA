class Solution {
public:
    
    int flips(string& s, int i, int hasOne, vector<vector<int>>& dp)
    {        
        int keep= 1e7;
        int flip= 1e7;
        
        if(i==s.size())
            return 0;
        
        if(dp[i][hasOne]!= -1)
            return dp[i][hasOne];
        
        if(s[i]=='0')
        {
            if(hasOne)
                flip = 1 + flips(s, i+1, 1, dp);
            else
            {
                keep = flips(s, i+1, 0, dp);
                flip = 1 + flips(s, i+1,1, dp);     
            }
            
        }
        else
        {
            if(hasOne)
                keep = flips(s, i+1, 1, dp);
            else
            {
                keep = flips(s, i+1, 1, dp);
                flip = 1 + flips(s, i+1, 0, dp);
            }
        }    
    return dp[i][hasOne] = min(keep, flip);
    }
    
    int minFlipsMonoIncr(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(2, -1));
        return flips(s, 0, 0, dp);
    }
};