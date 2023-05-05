//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
    bool isCycle(int source, vector<int>adj[], vector<int> vis)
    {
       vis[source] = 1;
       
       queue<pair<int, int>>q;
       q.push({source, -1});
       
       while(!q.empty())
       {
           int node = q.front().first;
           int parent = q.front().second;
           q.pop();
           for (auto n : adj[node])
           {
               if(vis[n] == 0)
               {
                   vis[n] = 1;
                   q.push({n, node});
               }
               else if (parent != n)
                    return true;
           }
       }
    return false;
        
    }
    bool dfs(int i, int parent, vector<int> adj[], vector<int>& vis)
    {
        vis[i] = 1;
        
        for (auto node : adj[i])
        {
            if(vis[node] ==0)
            {
                if(dfs(node, i, adj, vis) == true)
                    return true;
            }
            else if(node != parent)
                return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        
        for(int i=0; i<V; i++)
        {
           if (vis[i] == 0 && dfs(i, -1,adj, vis))
                return true;
        }
        return false;
    }
    
    
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends