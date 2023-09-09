class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int zeroCount = 0;
        long long res = 0;
        for(auto num : nums)
        {
            if(num == 0)
                res+= ++zeroCount;
            else
                zeroCount = 0;
        }
    return res;
    }
};