class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      
         
        vector<vector<pair<int,int>>>adj(n);
        
        
        for(auto i : flights)
            adj[i[0]].push_back({i[1], i[2]});
        
        
        queue<pair<int, pair<int,int>>>q;
        
        q.push({0,{src, 0}});
        vector<int>dist(n, 1e7);
        dist[src]=0;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops>k)
                continue;
            
            for(auto i : adj[node])
            {
               if(i.second + cost < dist[i.first])
               {
                   dist[i.first] = i.second+cost;
                   q.push({stops+1, {i.first, dist[i.first]}});
               }
            }
        }
        
        return dist[dst]==1e7 ? -1 : dist[dst];        
    }
};