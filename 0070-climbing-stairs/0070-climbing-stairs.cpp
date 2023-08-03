class Solution {
    int climbStairs(int n, vector<int>&dp) {
        if(n<=1)
            return 1;   
           
        //c(3) = c(2) + c(1);
        //c(4) =  c(3) + c(2);
        if(dp[n] != -1)
            return dp[n];
       return dp[n] = climbStairs(n-1, dp) + climbStairs(n-2,dp);  
        
    }
public:   
    int climbStairs(int n) {
      vector<int>dp(n+1, -1);  
     return climbStairs(n, dp);
    }
};