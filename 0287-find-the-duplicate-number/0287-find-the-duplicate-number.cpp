class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int res;
        for(int i = 0; i < nums.size(); i++)
        {
            int num = abs(nums[i]);
            
            if(nums[num] < 0)
            {
                res = num;
                break;
            }
            nums[num]*= -1;
        }
        for(int i = 0; i < nums.size(); i++)
            nums[i] = abs(nums[i]);
        
    return res;
    }
};