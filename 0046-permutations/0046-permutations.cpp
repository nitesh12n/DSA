class Solution {
private: 
    void permute(vector<int>& nums, int index, vector<vector<int>>& res)
    {
        if(index == nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=index; i< nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            permute(nums, index + 1, res);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>res;
        permute(nums, 0, res);
        return res;
    }
};