class Solution {
    vector<vector<int>>palindrome;
    bool isPalindrome(string& s, int i, int j)
    {
       
        if(i >= j) 
            return true;
		if(palindrome[i][j] != -1) 
            return palindrome[i][j];
		if(s[i] == s[j]) 
            return palindrome[i][j] = isPalindrome(s, i + 1, j - 1);
		return palindrome[i][j] = false;
    }
    
    int checkPartitioning(string& s, int index, int k, vector<vector<int>>& dp)
    {
        if(index == s.size())
           return k == 0 ? 1 : 0;     
         
        if(k < 0)
            return 0;
        
        if(dp[index][k] != -1)
            return dp[index][k];
        
        for(int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i))
                if(checkPartitioning(s, i + 1, k - 1, dp))
                    return dp[index][k] = 1;
        }
        return dp[index][k] = 0;         
    }
    
    
public:
    bool checkPartitioning(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(4, -1));
        palindrome = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return checkPartitioning(s, 0, 3, dp);
    }
};