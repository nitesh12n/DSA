class Solution {
        
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int res = 0, left = 0, right = 0;
        long sum = 0;
        
        while(right < nums.size())
        {
            long r = nums[right];
            sum+= r;            
            while(left <= right and r*(right - left + 1) - sum > k)
            {  
                sum-= nums[left];
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }       
        return res;
    }
};