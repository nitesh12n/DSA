class Solution {

    int findFirstOcc(vector<int>& nums, int target, int low, int high)
    {
        int mid, firstOcc=-1;
        while(low <=high)
        {
            mid = low + (high - low)/2;
            
            if(nums[mid] == target)
            {
                firstOcc = mid;
                high = mid -1;
            }
            else if (nums[mid]<target)
                low = mid + 1;      
        }
    return firstOcc;
    }
    int findLastOcc(vector<int>& nums, int target, int low, int high)
    {
        int mid, lastOcc=-1;
        while(low <=high)
        {
            mid = low + (high - low)/2;
            
            if(nums[mid] == target)
            {
                lastOcc = mid;
                low = mid +1;
            }
            else
                high = mid - 1;
                
        }
    return lastOcc;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size()-1;
        int mid;
        while(low <=high)
        {
            mid = low + (high - low)/2;
            
            if(nums[mid] == target)
            {
                int firstOcc = findFirstOcc(nums, target, low, high);
                if(firstOcc == -1)
                    return {-1,-1};
                int lastOcc = findLastOcc(nums, target, low, high);
                return {firstOcc, lastOcc};
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
    return {-1,-1};
    }
};