class Solution {
public:
    bool check(vector<int>& nums) {
     
        int n = nums.size();
        if(n == 1)
            return true;
        bool flag=false;
        
        for(int i = 0; i<n-1; i++)
        {
            if(nums[i] > nums[i+1]) 
            {
                if(flag)
                    return false;
                flag = true;
            }
        }
        if(flag and nums[0] < nums[n-1])
            return false;
    return true;
    }
};