class Solution {
    
    bool canJump(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index >= nums.size() - 1)
            return true;
        
        if(dp[index] != -1)
            return dp[index];
        
        for(int i = index + 1; i <= index + nums[index]; i++)
        {
            if(canJump(nums, i, dp))
                return dp[index] = true;
        }
        
    return dp[index] = false;
    }
public:
    bool canJump(vector<int>& nums) {  
        vector<int>dp(nums.size(), -1);
        return canJump(nums, 0, dp);
    }
};