class Solution {    
public:
    int nthUglyNumber(int n) {
        
        if(n == 1)
            return 1;
        vector<int>nums(1,1);
        int i = 0, j = 0, k = 0;

        while(nums.size() < n)
        {
            int newNum = min(nums[i]*2, min(nums[j]*3, nums[k]*5));
            nums.push_back(newNum);
            if(newNum == nums[i]*2)
                i++;
            if(newNum == nums[j]*3)
                j++;
            if(newNum == nums[k]*5)
                k++;
        }
    return nums.back();
    }
};