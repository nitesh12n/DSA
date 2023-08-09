class Solution {
    
    int length(vector<int>& nums, int i, int prev, vector<vector<int>>& dp)
    {
        if(i == nums.size())
            return 0;
        
        int l = -1e6;
        
        if(dp[i][prev+1] != -1)
            return dp[i][prev+1];
        //take
        if(prev == -1 or nums[prev] < nums[i]) 
            l = length(nums, i + 1, i, dp) + 1;
        
        //not take
        int r = length(nums, i + 1, prev, dp);
        
        return dp[i][prev+1] = max(l, r);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
        return length(nums, 0, -1, dp);
    }
};