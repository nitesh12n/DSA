class Solution {
    int jump(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index >= nums.size() - 1)
            return 0;       
        
        if(dp[index] != INT_MAX)
            return dp[index];
        
        int res = INT_MAX;
        for(int i = index + 1; i <= index + nums[index]; i++)
            res = min(res, jump(nums, i, dp));
        
    return dp[index] = res == INT_MAX ? res : (res + 1);
    }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), INT_MAX);
        return jump(nums, 0, dp);
    }
};