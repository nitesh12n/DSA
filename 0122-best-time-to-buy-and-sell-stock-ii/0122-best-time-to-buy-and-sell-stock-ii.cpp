class Solution {
public:
    int profit(vector<int>& prices, int i, int buy, vector<vector<int>>& dp)
    {
        if(i == prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        if(buy == 0)
            return dp[i][buy] = max(profit(prices, i + 1, 1, dp) - prices[i], profit(prices, i + 1, 0, dp));
        else
            return dp[i][buy] = max(profit(prices, i + 1, 1, dp), profit(prices, i +1, 0, dp) + prices[i]);
    }
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>>dp(prices.size() + 1, vector<int>(2, -1));
        return profit(prices, 0, 0, dp);
        //vector<vector<int>>dp(prices.size() + 1, vector<int>(2, 0));
        //dp[prices.size()][0] = dp[prices.size()][1] = 0;
        for(int i = prices.size() - 1; i >=0; i--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                if(buy == 0)
                    dp[i][buy] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                else
                    dp[i][buy] = max(dp[i + 1][1], dp[i + 1][0] - prices[i]);
            }
        }
        return dp[0][1];
    }
};