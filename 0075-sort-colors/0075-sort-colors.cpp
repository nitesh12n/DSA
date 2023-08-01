class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l =0, r = nums.size()-1;
        while(l < r)
        {
            while(l<r and nums[l] != 2)
                l++;
            while(l<r and nums[r] == 2)
                r--;
            
            if(l < r)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        l=0; 
        r=nums.size()-1;
        
        while(l < r)
        {
            while(l<r and nums[l] != 1)
                l++;
            while(l<r and nums[r] !=0)
                r--;
            
            if(l < r)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
    }
};