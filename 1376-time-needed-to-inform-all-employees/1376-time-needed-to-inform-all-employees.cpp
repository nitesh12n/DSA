class Solution {
    
    void dfs(int n, int id, vector<vector<int>>& subordinates, vector<int>& informTime, int time, int& res)
    {
        res = max(res, time);
        for(auto s : subordinates[id])
            dfs(n, s, subordinates, informTime, time + informTime[id], res);
    }
    
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)      {
        
        vector<vector<int>>subordinates(n);
        for(int i = 0; i < n; i++)
            if(manager[i] != -1)
                subordinates[manager[i]].push_back(i);
        int res = 0;
        dfs(n, headID, subordinates, informTime, 0, res);
        return res;
        
    }
};