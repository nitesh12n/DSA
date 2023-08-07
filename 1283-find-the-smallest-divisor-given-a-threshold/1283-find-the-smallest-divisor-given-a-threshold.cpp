class Solution {
    
    int getResult(vector<int>& nums, int mid)
    {
        int res=0;
        for(auto num : nums)
        {
            res+=(num/mid);
            if(num%mid)
                res++;
        }
        return res;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
     
        int low = 1, high = 0, res;
        
            for(auto num : nums)
                high = max(high, num);
        
        while(low <=high)
        {
            int mid = low + (high-low)/2;
            
            int result = getResult(nums, mid);
            
            if(result <= threshold)
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
    return res;
    }
};