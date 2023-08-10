class Solution {
    int isPossible(vector<int>& nums, int k, int maxSum)
    {
        int sum=0, splits=1;
        
        for(auto num : nums)
        {
            if(num + sum <= maxSum)
                sum+=num;
            else
            {
                sum=num;
                splits++;
            }
        }
    return splits <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=0, high=0, mid;
        
        for(auto num : nums)
        {
            low = max(low, num);
            high+=num;
        }
        while(low <= high)
        {
            mid = low + (high-low)/2;
            
            if(isPossible(nums, k, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
        
    }
};