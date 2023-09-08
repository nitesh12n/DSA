class Solution {
    int dfs(int node, int parent, vector<vector<pair<int, int>>>& graph)
    {   
        int res = 0;
        for(auto n : graph[node])
        {
            int neighbor = n.first, value = n.second;
            if(neighbor != parent)
                res = res + value + dfs(neighbor, node, graph);
        }
    return res;        
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int, int>>> graph(n);
        for (auto& c : connections) {
            graph[c[0]].push_back({c[1], 1});
            graph[c[1]].push_back({c[0], 0});
        }
        return dfs(0, -1, graph);
    }
};