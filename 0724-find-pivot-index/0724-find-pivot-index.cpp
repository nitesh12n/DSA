class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      
        int sum=0;
        for(auto num : nums)
            sum+=num;
        
        int currSum=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum-=nums[i];
            if(currSum == sum)
                return i;
            currSum+=nums[i];
        }
    return -1;
    }
};