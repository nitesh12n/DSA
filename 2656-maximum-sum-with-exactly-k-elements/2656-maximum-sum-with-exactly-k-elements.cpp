class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        int maxVal = 0;
        
        for(auto num : nums)
            maxVal = max(maxVal, num);
        
        int res = 0; 
        while(k--)
           res+= maxVal++;
        return res;
    }
};