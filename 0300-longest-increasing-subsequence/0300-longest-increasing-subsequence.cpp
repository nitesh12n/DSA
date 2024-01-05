class Solution {
    
    int lengthOfLIS(vector<int>& nums, int index, int prev, vector<vector<int>>& dp)
    {
        if(index == nums.size())
            return 0;
        
        
        if(dp[index][prev + 1] != -1)
            return dp[index][prev + 1];
        
        int notTake = lengthOfLIS(nums, index + 1, prev, dp);
        
        int take = 0;
        
        if(prev == -1 or nums[index] > nums[prev])
            take = 1 + lengthOfLIS(nums, index + 1, index, dp);
        
        return dp[index][prev + 1] = max(notTake, take);
    }
    
    
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return lengthOfLIS(nums, 0, -1, dp);
    }
};