class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int>m;
        int n = nums.size();
        for(auto num:nums)
        {
            m[num]++;
            if(m[num] > n/2)
                return num;
        }
        return 0;
    }
};