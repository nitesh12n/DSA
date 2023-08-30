class Solution {
    
    int maxProfit(vector<int>& prices, int index, int buy, vector<vector<int>>& dp)
    {
        if(index >= prices.size())
            return 0;
        
        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit;
        if(buy == 0)
            profit = max(-1*prices[index] + maxProfit(prices, index + 1, 1, dp), maxProfit(prices, index + 1, 0, dp));
        else
            profit = max(prices[index] + maxProfit(prices, index + 2, 0, dp), maxProfit(prices, index + 1, 1, dp));

    return dp[index][buy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return maxProfit(prices, 0, 0, dp);
    }
};