class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
       int l =0,r =0, n = nums.size();
       int sum = nums[l], res = INT_MAX; 
       while(l <= r and r < n)
       {         
           if(sum < target)
           {
               r++;
               if(r < n)
                    sum+= nums[r];
           }
           else 
           {
              sum-=nums[l]; 
              res = min(res, r - l + 1);
              l++; 
           } 
       }
        if(res == INT_MAX)
            return 0;
        return res;
    }
};