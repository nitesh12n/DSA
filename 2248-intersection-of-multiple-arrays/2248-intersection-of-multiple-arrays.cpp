class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        map<int,int>m;
        
        for(auto num : nums)
            for(auto i : num)
                m[i]++;
        
        int n = nums.size();
        vector<int>res;
        for(auto it : m)
            if(it.second == n)
                res.push_back(it.first);
        return res;
    }
};