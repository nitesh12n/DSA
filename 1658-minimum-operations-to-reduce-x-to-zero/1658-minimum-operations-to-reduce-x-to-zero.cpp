class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = 0;
        for(auto num : nums)
            sum+=num;
        
        int remaining = sum - x;
        if(remaining == 0)
            return nums.size();
        
        unordered_map<int, int>m;
        sum = 0;
        int res = INT_MIN;
        m[0] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
            if(m.find(sum - remaining) != m.end())
                res = max(res, i - m[sum-remaining]);
            m[sum] = i;
        }
        return res == INT_MIN ? -1 : nums.size() - res;
        
    }
};