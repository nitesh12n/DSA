class Solution {
    
    int getIndex(vector<int>& nums, int target)
    {
        int low = 0, res = -1, high = nums.size() - 1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] <= target)
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return res;
    }
    
    
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        vector<long long> res;
        vector<long long>prefixSum;
        long long totalSum = 0;
        sort(nums.begin(), nums.end());
        long long n = nums.size();
        for(auto num : nums)
        {
            totalSum += num;
            prefixSum.push_back(totalSum);
        }       
        
        for(auto query : queries)
        {
            long long index = getIndex(nums, query);
            long long operations = 0;
            if(index == -1)
                operations = totalSum - query*n; 
            else
                operations = query*(index + 1) - prefixSum[index] + totalSum - prefixSum[index] - query*(n - index - 1);

            res.push_back(operations);
        }
        return res;
    }
};