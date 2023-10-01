class Solution {
    int findLongestChain(vector<vector<int>>& pairs, int index, vector<int>& dp)
    {
        if(index == pairs.size())
            return 0;
       if(dp[index] != -1)
           return dp[index];
        
       int res = 1; 
       for(int i = index + 1; i < pairs.size(); i++)
       {
           if(pairs[index][1] < pairs[i][0])
               res = max(res, 1 + findLongestChain(pairs, i, dp));
       } 
        return dp[index] = res;
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int res = 0;
        vector<int>dp(pairs.size(), -1);
        for(int i = 0; i < pairs.size(); i++)
            res = max(res, findLongestChain(pairs, i, dp));
        
        return res;
    }
};