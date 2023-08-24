class Solution {
    int minCostTickets(vector<int>& days, int index, int coveredDays, vector<int>& costs, vector<vector<int>>&dp)
    {
        if(index == days.size() or coveredDays >= 365)
            return 0;
        
        if(dp[index][coveredDays] != -1)
            return dp[index][coveredDays];
        
        if(days[index] <= coveredDays)
            return dp[index][coveredDays] = minCostTickets(days, index + 1, coveredDays, costs, dp);
        
        //1 day
        int oneDay = costs[0] + minCostTickets(days, index + 1, days[index], costs, dp);
                
        //7 day
        int sevenDay = costs[1] + minCostTickets(days, index + 1, days[index] + 6, costs, dp);
        //30 day
        int thirtyDay = costs[2] + minCostTickets(days, index + 1, days[index] + 29, costs, dp);
        
      return dp[index][coveredDays] = min(oneDay, min(sevenDay, thirtyDay)); 
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<vector<int>>dp(n, vector<int>(365,-1)); 
        return minCostTickets(days, 0, 0, costs, dp);
    }
};