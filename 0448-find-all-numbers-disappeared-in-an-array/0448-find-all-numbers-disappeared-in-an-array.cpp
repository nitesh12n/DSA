class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i] != -1)
            {
                int j=nums[i];
                while(nums[j-1] != -1)
                {
                    int temp = nums[j-1];
                    nums[j-1] = -1;
                    j = temp;
                }
            }
        }
        vector<int>res;
        for(int i=0; i<nums.size();i++)
        {   
            if(nums[i] != -1)
                res.push_back(i+1);
        }
        return res;
    }
};