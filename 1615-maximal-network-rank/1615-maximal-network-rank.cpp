class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<vector<int>>adj(n, vector<int>(n, 0));
        
        for(auto it : roads)
        {
            adj[it[0]][it[1]] = 1; 
            adj[it[1]][it[0]] = 1; 
        }
        vector<int>indegree(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            for(int it : adj[i])
            {
                if(it == 1)
                    indegree[i]++;
            }
        }
        int res = 0;
        unordered_set<int>s;
        for(int i = 0; i < n; i++)
        {            
            for(int j = i + 1; j< n; j++)
            {
                res = max(res, indegree[j] + indegree[i] + (adj[i][j] == 1 ? -1 : 0));
            }
        }
    return res;
    }
};