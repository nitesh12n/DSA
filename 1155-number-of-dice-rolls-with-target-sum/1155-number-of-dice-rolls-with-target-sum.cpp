class Solution {
    int numRolls(int n, int k, int target, vector<vector<int>>& dp)
    {
        const int mod  = 1e9 + 7;
        
        if(target < 0)
            return 0;
        
        if(n == 0)
            return target == 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int res = 0;
        for(int i = 1; i <= k; i++)
        {
            
            if(target >= i)
            {
                res = (res + numRolls(n - 1, k, target - i, dp))%mod;
            }
        }
        return dp[n][target] = res;
    }
    
    
    
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n + 1, vector<int>(target + 1, -1));
        return numRolls(n, k, target, dp);
    }
};