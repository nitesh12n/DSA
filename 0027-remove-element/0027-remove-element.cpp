class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int j = nums.size()-1;

        for(int i=0;i<nums.size() and j>i;i++)
        {
            if(nums[i]==val)
            {
                while(j>=i and nums[j]==val)
                    j--;
                if(j>=0 and i<j)
                    swap(nums[i],nums[j]);
            }
        }
        int i=nums.size()-1;
        while(i>=0 and nums[i] == val)
            i--;
        
        return i+1;
        
    }
};