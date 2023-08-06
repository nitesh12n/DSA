class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
     sort(nums.begin(), nums.end());
     int n = nums.size();
     int i=0;
     set<vector<int>>s;
     while(i < n-2)
     {
         int j = i + 1;
         int k = n-1;
         while(j < k and k < n)
         { 
             int sum =nums[i] + nums[j] + nums[k];
             if(sum < 0)
                 j++;
             else if(sum > 0)
                 k--;
             else
             {
                 s.insert({nums[i], nums[j], nums[k]});
                 j++,k--;
                 while(j < n and nums[j] == nums[j-1])
                     j++;
                 while( k > i and nums[k] == nums[k+1])
                     k--;
             }
         }
         i++;
         while(i < n-2 and nums[i] == nums[i-1])
            i++;      
     }
    return vector<vector<int>>(s.begin(), s.end());
    }
};