class Solution {
    void permute(vector<int>& nums, int index, set<vector<int>>& res)
    {
        if(index == nums.size())
        {
            res.insert(nums);
            return;
        }
        
        for(int i = index; i <nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            permute(nums, index + 1, res);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>res;
        permute(nums, 0, res);
        return vector<vector<int>>(res.begin(), res.end());
        
    }
};