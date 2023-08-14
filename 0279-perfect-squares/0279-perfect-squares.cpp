class Solution {
    int numSquares(vector<int>& nums, int index, int sum, int n, vector<vector<int>>& dp)
    {
        if(sum == n)
            return 0;
        int res = 1e7;
        if(sum > n || index == nums.size())
            return res;
        
        if(dp[index][sum] != -1)
            return dp[index][sum];
        
        for(int i=index; i <nums.size(); i++)
        {
            if(sum + nums[i] <= n)
                res = min(res, 1 + numSquares(nums, i, sum + nums[i], n, dp));
        }
    return dp[index][sum] = res;
    }
    
public:
    int numSquares(int n) {
        
        int num = 1;
        vector<int>nums;
        while(num*num <=n)
        {
            nums.push_back(num*num);
            num++;
        }
        reverse(nums.begin(), nums.end());
        vector<vector<int>>dp(nums.size(), vector<int>(n+1, -1));
        return numSquares(nums, 0, 0, n, dp);        
    }
};