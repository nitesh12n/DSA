class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int>m1;
        unordered_map<int, int>m2;
        vector<vector<int>>res(2);
        for(auto num : nums1)
            m1[num]= 1;
        
        for(auto num : nums2)
        {
            if(m1.find(num) == m1.end())
            {
                res[1].push_back(num);
                m1[num]=2;
                
            }
            m2[num]=1;
        }
        for(auto num : nums1)
        {
            if(m2.find(num) == m2.end())
            {
                res[0].push_back(num);
                m2[num] = 2;
            }
        }
        return res;
        
    }
};