class Solution {
    bool hasCycle(int node, int parent, vector<vector<int>>& graph, vector<int>& vis)
    {
        vis[node] = 1;
        
        for( auto n : graph[node])
        {
            if(n != parent and (vis[n] == 1 or hasCycle(n, node, graph, vis)))
                return true;
        }
    return false;
    }
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>graph(n);
        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int>vis(n, 0);
        if(hasCycle(0, -1, graph, vis))
            return false;
        
        for(auto it : vis)
            if(it == 0)
                return false;
        
        return true;
    }
};