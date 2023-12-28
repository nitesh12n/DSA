class Solution {
     int getChangeCount(string s, int start, int end)
     {
        int res = 0;  
        while(start < end)
        {
            if(s[start] != s[end])
                res++;
            start++;
            end--;
        }
         return res;
     }
    
     int palindromePartition(string s, int index, int k, vector<vector<int>>& dp) {
         
         int res = INT_MAX;

         if(index == s.size() or k < 0)
             return k == 0 ? 0 : res;
            
         if(dp[index][k] != -1)
             return dp[index][k];
         
         for(int i = index; i < s.size(); i++)
         {           
             int count = palindromePartition(s, i + 1, k - 1, dp);
             if(count != INT_MAX)
                res = min(res, getChangeCount(s, index, i) + count);
         }
         return dp[index][k] = res;
    }
    
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>>dp(s.size(), vector<int>(k + 1, -1));
        return palindromePartition(s, 0, k, dp);
    }
};