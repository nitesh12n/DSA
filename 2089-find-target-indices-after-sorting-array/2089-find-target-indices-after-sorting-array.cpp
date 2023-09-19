class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int index = 0, freq = 0;
        for(auto num : nums)
        {
            if(num < target)
                index++;
            else if(num == target)
                freq++;
        }
        vector<int>res;
        for(int i = index; i < index + freq; i++)
            res.push_back(i);
        return res;
    }
};