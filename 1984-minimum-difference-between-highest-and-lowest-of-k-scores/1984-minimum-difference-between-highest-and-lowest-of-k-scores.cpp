class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int minDiff=1e7;
        
        for(int i=0; i<=n-k;i++)
            minDiff = min(minDiff, nums[i+k-1]-nums[i]);
        
        return minDiff;
    }
};