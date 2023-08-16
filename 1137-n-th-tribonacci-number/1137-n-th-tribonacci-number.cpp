class Solution {
public:

    int tribonacci(int n, vector<int>& dp)
    {
        if(n <=1)
            return n;
        if(n == 2)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = tribonacci(n-1, dp) + tribonacci(n-2, dp) + tribonacci(n-3, dp);
    }
    int tribonacci(int n) {
        
        vector<int>dp(n + 1, -1);
        return tribonacci(n, dp);
    }
    
};