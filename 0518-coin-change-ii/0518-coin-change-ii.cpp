class Solution {
    
    int change(int amount, int index, vector<int>& coins, vector<vector<int>>& dp) {
        
        if(amount == 0)
            return 1;
        
        if(amount < 0 or index == coins.size())
            return 0;
        
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int take = 0;
        if(amount >= coins[index])
            take = change(amount - coins[index], index, coins, dp);
        
        int notTake = change(amount, index + 1, coins, dp);
        
        return dp[index][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, -1));
        return change(amount, 0, coins, dp);
    }
};