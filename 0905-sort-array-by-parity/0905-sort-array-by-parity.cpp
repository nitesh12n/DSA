class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        vector<int>res, even, odd;
        
        for(auto num : nums)
        {
            if(num%2 == 0)
                even.push_back(num);
            else
                odd.push_back(num);
        }
        res = even;
        
        for(auto num : odd)
            res.push_back(num);
    return res;
    }
};