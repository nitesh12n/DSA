class Solution {
public:
    int rob(vector<int>& nums, int start, int i, vector<int>& dp)
    {
        if(i<start)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(nums[i] + rob(nums, start, i-2, dp), rob(nums, start, i-1, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        if(n==1)
            return nums[0];
        return max(rob(nums,0, n-2, dp1), rob(nums, 1, n-1, dp2));
    }
};