class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        if(n < 4)
            return {};
        for(int a = 0; a < n;a++)
        {
            if(a > 0 and nums[a] == nums[a-1])
                continue;
            for(int b = a + 1; b < n; b++)
            {
                 if(b > a + 1 and nums[b] == nums[b-1])
                    continue;
                int c = b + 1;
                int d = n-1;              
                
                while(c < d)
                {
                    long sum = nums[a];
                    sum+= nums[b];
                    sum+= nums[c];
                    sum+= nums[d];
                    
                    if(sum < target)
                        c++;
                    else if (sum > target)
                        d--;
                    else
                    {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while(c < d and nums[c] == nums[c-1])
                            c++;
                        while(c < d and nums[d] == nums[d+1])
                            d--;         
                    }
                }
            }   
        }
    return res;
    }
};