class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        unordered_map<int,int> m;
        vector<vector<int>> res;
        
        for(auto num : nums)
        {
            if(res.size() <= m[num])
                res.push_back({num});
            else
                res[m[num]].push_back(num);
            m[num]++;
        }
        return res;
    }
};