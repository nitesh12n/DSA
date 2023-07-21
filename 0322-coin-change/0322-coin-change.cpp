class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount, int index, vector<vector<int>>& dp)
    {
        if(index<0 || amount <0)
            return 1e7;
        if(amount==0)
            return 0;
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int count=1e7;
        if(amount >=coins[index])
            count = 1 + coinChange(coins, amount - coins[index], index, dp);
        
        return dp[index][amount] = min(count, coinChange(coins, amount, index-1, dp));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        int res = coinChange(coins, amount, coins.size()-1, dp);
        if(res == 1e7)
            return -1;
        return res;
    }
};