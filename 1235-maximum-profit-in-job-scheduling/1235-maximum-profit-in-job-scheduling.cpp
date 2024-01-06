class Solution {
    
    int scheduling(vector<vector<int>>& times, vector<int>& startTime, int index, vector<int>&dp)
    {
        if(index == times.size())
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        
        int notTake = scheduling(times, startTime, index + 1, dp);

        int i = lower_bound(startTime.begin(), startTime.end(), times[index][1]) - startTime.begin();
        int take = times[index][2] + scheduling(times, startTime, i, dp);            
        
        return dp[index] = max(take, notTake);
    }
    
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
               
        vector<vector<int>>times;
        int maxEndTime = 0;
        for(int i = 0; i < startTime.size(); i++)
        {
            times.push_back({startTime[i], endTime[i], profit[i]});
            maxEndTime = max(maxEndTime, endTime[i]);
        }
        
        sort(times.begin(), times.end());
        for(int i = 0; i < startTime.size(); i++)
            startTime[i] = times[i][0];
        
        vector<int>dp(times.size(), -1);
        
        return scheduling(times, startTime, 0, dp);
        
    }
};