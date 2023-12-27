class Solution {
    bool isPalindrome(string& str, int start, int end)
    {
        int low = start; int high = end;
        while(low<high)
        {
            if(str[low] != str[high])
                return false;
            low++;
            high--;
        }
    return true;
    }
    
    int minCut(string& s, int index, vector<int>& dp)
    {
        if(index == s.size())
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int res = 2001;
        for(int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i))
                res = min(res, 1 + minCut(s, i + 1, dp));
        }
        return dp[index] = res;
    }
    
public:
    int minCut(string s) {
        vector<int>dp(s.size() + 1, -1);
        return minCut(s, 0, dp) - 1;
    }
};