class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low =0, high = nums.size()-1;
        int mid;
                
        while(low<=high)
        {
            mid = low + (high - low)/2;
            
            if(nums[mid] == target)
                return true;
            
            if(nums[low] == nums[mid] and nums[mid] == nums[high])
            {
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target and target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(nums[mid] < target and target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    return false;
    }
};