class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>suffixSum(n);
        vector<int>res;
        suffixSum[n-1] = 0;
        
        for(int i = n - 2; i >= 0; i--)
            suffixSum[i] = suffixSum[i+1] + nums[i+1];
        
        int prefixSum = 0;
        for(int i = 0; i < n; i++)
        {
            int val = nums[i]*i - prefixSum + suffixSum[i] - nums[i]*(n-i-1);
            prefixSum+=nums[i];
            res.push_back(val);
        }
        
    return res;
    }
};