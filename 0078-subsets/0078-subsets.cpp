class Solution {
public:
    void subsets(vector<int>& nums, int index, vector<int>&temp, vector<vector<int>>&res)
    {
        
        res.push_back(temp);
        for(int i = index; i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            subsets(nums, i+1, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>res;
        subsets(nums, 0, temp, res);
        return res;
    }
};