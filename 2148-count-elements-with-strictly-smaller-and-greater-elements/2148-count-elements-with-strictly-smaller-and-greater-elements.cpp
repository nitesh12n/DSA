class Solution {
public:
    int countElements(vector<int>& nums) {
        
        int minValue = INT_MAX, maxValue = INT_MIN;
        for(auto num : nums)
        {
            minValue = min(num, minValue);
            maxValue = max(num, maxValue);
        }
        
        int res = 0;
        for(auto num : nums)
            if(num > minValue && num < maxValue)
                res++;
              
        return res;
    }
};