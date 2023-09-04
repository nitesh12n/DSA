class Solution {
    
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& path, vector<int>& check)
    {
        vis[node] = 1;
        path[node] = 1;
        for(auto n : graph[node])
        {
            if(vis[n] == 0)
            {  
                if(!dfs(n, graph, vis, path, check))
                    return false;
            }
            else if(path[n] == 1)
                return false;   
        }
    path[node] = 0;
    check[node] = 1;
    return true;        
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>vis(n, 0);
        vector<int>path(n, 0);
        vector<int>check(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
                dfs(i, graph, vis, path, check);
        }
        vector<int>res;
        for(int i = 0; i < n; i++)
            if(check[i])
                res.push_back(i);
        
    return res;
        
    }
};