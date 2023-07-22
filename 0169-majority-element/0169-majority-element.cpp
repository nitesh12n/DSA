class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count=0;
        int res;
        for(auto num:nums)
        {
            if(count==0)
                res = num;
            count+= num ==  res ? 1 : -1;
        }
        return res;
    }
};