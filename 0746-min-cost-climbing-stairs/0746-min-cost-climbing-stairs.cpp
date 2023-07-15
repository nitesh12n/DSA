class Solution {
public:
    int stairs(vector<int>& cost, int i, vector<int>& dp)
    {
        if(i<0)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = cost[i] + min(stairs(cost, i-1, dp), stairs(cost, i-2, dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int>dp(n, -1);
        return min(stairs(cost, n-1, dp), stairs(cost,n-2, dp));
    }
};