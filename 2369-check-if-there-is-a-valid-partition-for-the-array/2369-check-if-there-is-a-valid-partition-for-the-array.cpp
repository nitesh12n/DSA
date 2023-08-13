class Solution {
    
    bool validPartition(vector<int>& nums, int index, vector<int>&dp)
    {
        if(index == nums.size())
            return true;
        
        if(dp[index]  != -1)
            return dp[index];
        
       //2
       if(index + 1 < nums.size() and nums[index] == nums[index + 1])
           if(validPartition(nums, index + 2, dp))
               return dp[index]= true;
        
        if(index + 2 < nums.size())
        {
        if(nums[index] == nums[index + 1] and nums[index + 1] == nums[index + 2])
          if(validPartition(nums, index + 3, dp))
              return dp[index] = true;

        if((nums[index] + 1) == nums[index + 1] and (nums[index + 1] + 1)== nums[index + 2])
          return dp[index] = validPartition(nums, index + 3, dp);  
        }
        
    return dp[index] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return validPartition(nums, 0, dp);
    }
};