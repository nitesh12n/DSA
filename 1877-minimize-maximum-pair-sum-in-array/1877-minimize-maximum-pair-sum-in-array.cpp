class Solution {
public:
    int minPairSum(vector<int>& nums) { 
        
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.size() - 1, res = 0;      
        while(left < right)
        {
            res = max(nums[left] + nums[right], res);
            left++;
            right--;
        }
        return res;

    }
};