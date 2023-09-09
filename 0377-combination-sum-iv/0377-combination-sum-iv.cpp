class Solution {
    int combinationSum(vector<int>& nums, int target, vector<int>& dp)
    {
        if(target == 0)
            return 1;
        
        if(target < 0)
            return 0;
        
        if(dp[target] != -1)
            return dp[target];
        
        int res = 0;
        for(int i = 0; i<nums.size(); i++)
            res+=combinationSum(nums, target - nums[i], dp);

        return dp[target] = res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target + 1, -1);
        return combinationSum(nums, target, dp);
    }
};