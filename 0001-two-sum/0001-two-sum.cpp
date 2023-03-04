class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int>v;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(v.find(nums[i])==v.end())
                v[nums[i]] = i;
            if(v.find(target - nums[i])!=v.end() && i!=v[target - nums[i]])
                    return {i, v[target - nums[i]]};
              
        }
        return {-1,-1};
    }
};