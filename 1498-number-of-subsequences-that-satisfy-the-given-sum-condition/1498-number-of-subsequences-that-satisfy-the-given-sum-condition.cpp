class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());        
        vector<int> power;
        power.push_back(1);
        for (int i = 1; i < nums.size(); ++i) 
        {
            power.push_back((2 * power[i - 1]) % mod);
        }
        
        int i = 0, j=nums.size()-1, res = 0;    
        while(i<=j)
        {
            if(nums[i] + nums[j] <= target)
             {
                res+=power[j - i]%mod;
                res%=mod;
                i++;
             }
            else
                j--;
        }
    return res;
    }
};