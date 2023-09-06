class Solution {
    
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis)
    {
        vis[node] = 1;
        
        for( auto n : graph[node])
        {
            if(vis[n] == 0)
                dfs(n, graph, vis);
        }
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>graph(n);
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int res = 0;
        vector<int>vis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, graph, vis);
                res++;
            }
        }
    return res;
    }
};