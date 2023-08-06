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
         while(j < k)
         { 
             int sum =nums[i] + nums[j] + nums[k];
             if(sum < 0)
                 j++;
             else if(sum > 0)
                 k--;
             else
             {
                 s.insert({nums[i], nums[j], nums[k]});
                 k--;
             }
         }
         i++;      
     }
    return vector<vector<int>>(s.begin(), s.end());
    }
};