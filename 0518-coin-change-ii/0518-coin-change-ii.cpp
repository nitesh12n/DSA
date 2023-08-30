class Solution {
    
    
    int change1(int amount, int index, vector<int>& coins, vector<vector<int>>& dp) {
        
        if(amount == 0)
            return 1;
        
        if(amount < 0 or index == coins.size())
            return 0;
        
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int take = 0;
        if(amount >= coins[index])
            take = change1(amount - coins[index], index, coins, dp);
        
        int notTake = change1(amount, index + 1, coins, dp);
        
        return dp[index][amount] = take + notTake;
    }
    int change2(int amount, int index, vector<int>& coins, vector<vector<int>>& dp) {
        
        if(amount == 0)
            return 1;
        
        if(amount < 0 or index == coins.size())
            return 0;
        
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        int res = 0;
        for(int i = index; i < coins.size(); i++)
        {
            if(amount >= coins[i])
                res+= change2(amount - coins[i], i,  coins, dp);
        }
        
        return dp[index][amount] = res;
    }
    int change3(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, 0));
 
        for(int i = 0; i < coins.size(); i++)
        {
           for(int j = 0; j <= amount; j++)
            { 
               if(j==0)
                 dp[i][j] = 1;
               if(i==0)
                   dp[i][j] = j%coins[0] ? 0 : 1;
               else if(j>=coins[i])
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
               else
                   dp[i][j]  = dp[i-1][j];
            }
        }
    return dp[coins.size()-1][amount];
    }
    
    
    
public:
    int change(int amount, vector<int>& coins) {
        //vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, -1));
        //return change1(amount, 0, coins, dp);
        return change3(amount, coins);
    }
    
    
};