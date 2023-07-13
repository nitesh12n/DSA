//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
  private:
     void topologicalSort(vector<vector<pair<int,int>>>& adj, int node, vector<int>& vis, stack<int>& s)
     {
         vis[node]=1;
         
         for(auto i : adj[node])
         {
             if(vis[i.first]==0)
                topologicalSort(adj, i.first, vis, s);
         }
         s.push(node);
         
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        vector<int>vis(N, 0);
        stack<int>s;
        
        for(int i=0; i<M;i++)
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            
        topologicalSort(adj,0 ,vis, s);
        
        vector<int>dist(N, INT_MAX);
        dist[0]=0;
        
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            
            for(auto it: adj[node])
                dist[it.first] = min(dist[it.first], dist[node] + it.second);
        }
        for(int i=0; i<N;i++)
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends