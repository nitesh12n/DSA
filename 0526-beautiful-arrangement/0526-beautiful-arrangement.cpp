class Solution {
public:
    int permute(vector<int> nums, int index)
    {
        if(index == nums.size())
            return 1;
        
        int count = 0;
        for(int i = index; i < nums.size(); i++)
        {  
            swap(nums[i], nums[index]);
            if(nums[index]%(index + 1) == 0 || (index+1)%nums[index] == 0)
              count+=permute(nums, index + 1);
            swap(nums[index], nums[i]);
        }
        return count;
    }
    int countArrangement(int n) {
        vector<int>nums;
        for(int i = 1; i <=n; i++)
            nums.push_back(i);

        return permute(nums, 0);
    }
};