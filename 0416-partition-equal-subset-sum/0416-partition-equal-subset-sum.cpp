class Solution {
    bool subsetSumToK(int n, int k, vector<int> &arr, vector<vector<int>>& dp)
    {
        if(k==0)
            return true;

        if(k < 0 or n < 0)
            return false;

        if(dp[n][k] != -1)
            return dp[n][k];
    
        return dp[n][k] = subsetSumToK(n-1, k, arr, dp) || subsetSumToK(n-1, k - arr[n], arr, dp);
}
    public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0,n = nums.size();
        for(auto num : nums)
            sum+=num;    
        
        if(sum%2 == 1)
            return false;
        
        int k = sum/2;
        
        vector<vector<int>>dp(n, vector<int>(k+1, -1));
        
    return subsetSumToK(n-1, k, nums, dp);
    }
};