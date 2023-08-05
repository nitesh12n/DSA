class Solution {
    void subsets(vector<int>& nums, int index, vector<int>& temp, vector<vector<int>>& res)
    {
        res.push_back(temp);
        
        for(int i = index; i<nums.size(); i++)
        {
            if(i > index and nums[i-1] == nums[i])
                continue;
            temp.push_back(nums[i]);
            subsets(nums, i+1, temp, res);
            temp.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        subsets(nums, 0, temp, res);
        return res;
    }
};