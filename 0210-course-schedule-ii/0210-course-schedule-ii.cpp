class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>&path, vector<int>& res) {

        vis[node] = 1;
        path[node] = 1; 
        for(auto n : graph[node])
        {
            if(path[n] == 1)
                return false;
            if(vis[n] == 0)
                if(dfs(n, graph, vis, path, res) == false)
                    return false;
        }
        path[node] = 0; 
        res.push_back(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>graph(numCourses);
                
        for(vector<int> p : prerequisites)
            graph[p[1]].push_back(p[0]);
        
        vector<int>vis(numCourses, 0);
        vector<int>path(numCourses,0);
        vector<int>res;
        
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i] == 0)
                if(dfs(i, graph, vis, path, res) == false)
                    return {};
        }
        reverse(res.begin(), res.end());
    return res;
    }
};