class Solution {
    
    
    int minDifficulty(vector<int>& jobDifficulty, int index, int d, vector<vector<int>>&dp)
    {
        int difficulty = 0;
        int res = INT_MAX;
        if(index > jobDifficulty.size())
            return 0;
        
        if(index == jobDifficulty.size() and d > 0)
            return res;
        
        if(dp[index][d] != -1)
            return dp[index][d];
        
        if(d == 1)
        {
            for(int i = index; i < jobDifficulty.size(); i++)
                difficulty = max(difficulty, jobDifficulty[i]);
            return dp[index][d] = difficulty;
        }


        for(int i = index; i < jobDifficulty.size() - d + 1; i++)
        {
            difficulty = max(difficulty, jobDifficulty[i]);
            int val = minDifficulty(jobDifficulty, i + 1, d - 1, dp);
            if(val != INT_MAX)
                res = min(res, val + difficulty);
        }
        return dp[index][d] = res;    
    }
    
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        if(d > jobDifficulty.size())
            return -1;
        
        vector<vector<int>>dp(jobDifficulty.size() + 1, vector<int>(d + 1, -1));
        int res =  minDifficulty(jobDifficulty, 0, d, dp);
        if(res == INT_MAX)
            return -1;
        return res;
    }
};