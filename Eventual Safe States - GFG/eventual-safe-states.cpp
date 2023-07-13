//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<vector<int>>adjRev(V);
        vector<int>indegree(V,0);
        vector<int>res;
        queue<int>q;
        
        for(int i=0; i<V;i++)
        {
            for(auto n : adj[i])
            {
                adjRev[n].push_back(i);
                indegree[i]++;
            }
        }
        
        for(int i=0; i<V;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto n : adjRev[node])
            {
                indegree[n]--;
                if(indegree[n]==0)
                    q.push(n);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends