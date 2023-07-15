class Solution {
public:
    int rob(vector<int>& nums, int i, vector<int>& dp)
    {
        if(i<0)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(nums[i] + rob(nums, i-2, dp), rob(nums, i-1, dp));
    }
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size(), -1);
        return rob(nums, nums.size()-1, dp);
    }
};