class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        
        int left=-1,minIndex=-1,maxIndex=-1;
        long long ans =0;
        
        
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i] < minK or nums[i] > maxK)
                left = i;
            
            if(nums[i] == minK)
                minIndex = i;
            if(nums[i] == maxK)
                maxIndex = i;
            
            ans = ans + max(0, min(minIndex, maxIndex)-left);
        }
        return ans;
        
    }
};