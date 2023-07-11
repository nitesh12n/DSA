class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>&vis, vector<int>&path, vector<int>&check, int node)
    {
     check[node] = 0;    
     vis[node] = 1;
     path[node]=1;
        for(auto n : graph[node])
        {
            if(vis[n]==0)
            {
                vis[n]=1;
                path[n]=1;
                if(dfs(graph, vis, path, check, n) == true)
                {
                    check[node]=0;
                    return true;    
                }
                path[n]=0;
            }
            else if(path[n] == 1)
            {
                check[node]=0;
                return true;
            }
        }
    check[node] = 1;
    path[node]=0;
    return false;    
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>vis(n, 0);
        vector<int>path(n,0);    
        vector<int>safeNodes;
        vector<int>check(n, 0);

        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
                dfs(graph,vis,path,check, i);
        }
         for(int i=0;i<n;i++)
         {
             if(check[i]==1)
                 safeNodes.push_back(i);
         }
        return safeNodes;
    }
};