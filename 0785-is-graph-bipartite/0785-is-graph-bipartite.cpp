class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>&color, int c, int node)
    {
        color[node] = c;
        
        for(auto n : graph[node])
        {
            if(color[n] == -1)
            {
                if(dfs(graph, color, !c, n) == false)
                    return false;
            }
            else if(color[n] == c)
                return false;
                
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>color(n, -1);
        
        for(int i = 0; i<n;i++)
        {
            if(color[i] == -1 && dfs(graph, color, 0, i) == false)
                return false;
        }
    return true;    
    }
};