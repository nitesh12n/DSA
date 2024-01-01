class Solution {
    
    int getDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes, int index, string& bikeMask, unordered_map<string, int>&dp)
    {
        if(index == workers.size())
            return 0;
        
        string key = bikeMask;
        if(dp.find(key) != dp.end())
            return dp[key];
        
        int res = INT_MAX;
        for(int i = 0; i < bikeMask.size(); i++)
        {
            if(bikeMask[i] == '0')
            {
                bikeMask[i] = '1';
                int val = assignBikes(workers, bikes, index + 1, bikeMask, dp);
                bikeMask[i] = '0';      
                if(val != INT_MAX)
                    res = min(res, val + getDistance(workers[index], bikes[i]));
            }
        }
        return dp[key] = res;
    }
    
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes)     {
        string bikeMask(bikes.size(), '0');
        unordered_map<string, int>dp;
        return   assignBikes(workers, bikes, 0, bikeMask, dp); 
    }
};