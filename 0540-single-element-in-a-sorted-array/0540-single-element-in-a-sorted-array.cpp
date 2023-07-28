class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int size = nums.size();
        int low =0, high = size-1, mid;
        
        if(size == 1 || nums[0] != nums[1])
            return nums[0];
        if(nums[size-2] != nums[size-1])
            return nums[size-1];
        
        while(low<=high)
        {
            mid = low +(high-low)/2;
            
            if(nums[mid-1] != nums[mid] and nums[mid] != nums[mid+1])
                return nums[mid];
            
            if(mid%2==0 and nums[mid] == nums[mid+1] || mid%2 == 1 and nums[mid] == nums[mid-1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};