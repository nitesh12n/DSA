class Solution {
    
    int minCost(vector<vector<int>>& costs, int index, int prev, vector<vector<int>>& dp)
    {
        if(index == costs.size())
            return 0;
        
        if(dp[index][prev + 1] != -1)
            return dp[index][prev + 1];
        
        int cost = INT_MAX;
        for(int i=0; i<3; i++)
        {
            if(prev == -1 or i != prev)                
                cost = min(cost, costs[index][i] + minCost(costs, index + 1, i, dp)); 
        }
    return dp[index][prev + 1]= cost;
    }
    
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>>dp(costs.size(), vector<int>(4, -1));
        return minCost(costs, 0, -1, dp);
    }
};