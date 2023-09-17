class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        vector<vector<int>>arr;
        int rows = nums.size(), cols = nums[0].size();
        for(auto num : nums)
        {
            vector<int>temp = num;
            sort(temp.begin(), temp.end());
            arr.push_back(temp);
        }
        int res = 0;
        for(int i = 0; i < cols; i++)
        {
           int maxValue = 0;
           for(int j = 0; j < rows; j++)
                maxValue = max(maxValue, arr[j][i]);
            res+=maxValue;
        }
    return res;
    }
};