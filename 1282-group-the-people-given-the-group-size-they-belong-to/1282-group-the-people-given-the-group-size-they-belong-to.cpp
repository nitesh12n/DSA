class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        unordered_map<int, vector<int>>m;
        int n = groupSizes.size();
        for(int i = 0; i< n; i++)
            m[groupSizes[i]].push_back(i);
        
        vector<vector<int>>res;
        for(auto it : m)
        {
            int size = it.first;
            vector<int>temp = {};
            for(auto index : it.second)
            {
                if(temp.size() == size)
                {
                    res.push_back(temp);
                    temp = {};
                }
            temp.push_back(index);
            }
            if(temp.size() > 0)
                res.push_back(temp);
        }
    return res;
    }
};