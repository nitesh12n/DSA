class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        unordered_map<int,int> m;
        vector<vector<int>> res;
        for(auto num : nums)
            m[num]++;
        
        for(auto it : m)
        {
            int freq = it.second;
            int row = 0;
            while(freq-- > 0)
            {
                if(res.size() <= row)
                    res.push_back({it.first});
                else
                    res[row].push_back(it.first);
                row++;
            }
        }
        return res;
    }
};