class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int size = nums.size();
        int res = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for(int i=0; i<size; i++)
        {
           if(prefix==0)
               prefix=1;
           if(suffix==0)
               suffix=1;
            
            prefix*=nums[i];
            suffix*=nums[size-i-1];
            
            res = max(res, max(prefix,suffix));
        }
    return res;
    }
};