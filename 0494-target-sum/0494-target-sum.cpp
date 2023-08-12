class Solution {
    
    int findTarget(vector<int>& nums, int i, int value, int target)
    {
        if(i == nums.size())
            return value == target;    
        
        //+
        int l = findTarget(nums, i + 1, value + nums[i], target);  
        //-
        int r = findTarget(nums, i + 1, value - nums[i], target);  

        return l + r;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return findTarget(nums, 0, 0, target);
    }
};