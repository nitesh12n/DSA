class Solution {
    
    int splitArray(vector<int>& nums, int k, int index, vector<vector<int>>& dp)
    {
        if(k==0 and index < nums.size() or k> 0 and index == nums.size())
            return INT_MAX;
        if(k==0)
            return 0;
        
       if(dp[index][k] != -1)
           return dp[index][k];
        
        int sum = 0, minSum=INT_MAX;
        
        for(int i=index; i < nums.size(); i++)
        {
            sum+=nums[i];
            int res = max(sum, splitArray(nums, k-1, i + 1, dp));   
            minSum = min(res, minSum);
        }
    
    return dp[index][k] = minSum;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
     vector<vector<int>>dp(nums.size(), vector<int>(k + 1, -1));
        return splitArray(nums, k, 0, dp);
    }
};