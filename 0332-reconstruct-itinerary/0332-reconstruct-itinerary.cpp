class Solution {
    
    vector<string> dfs(map<string, vector<string>>& graph, string airport, vector<string>& temp, unordered_map<string, int>&freq, int edges)
    {
        if(temp.size() == edges + 1)
            return temp;
        
        for(auto it : graph[airport])
        {
            string key = airport + it;
            
            if(freq[key] > 0)
            {
                freq[key]--;
                temp.push_back(it);
                auto res = dfs(graph, it, temp, freq, edges);
                if(res.size() > 0)
                    return res;
                temp.pop_back();
                freq[key]++;
            }
        }
    return {};
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       
        map<string, vector<string>>graph;
        unordered_map<string, int>freq;
        for(auto ticket : tickets)
        {
            graph[ticket[0]].push_back(ticket[1]);
            freq[ticket[0] + ticket[1]]++;
        }
        
        for(auto it : graph)
        {
            auto v = it.second;
            sort(v.begin(), v.end());
            graph[it.first] = v;
        }
        
        vector<string>temp;
        temp.push_back("JFK");
        return dfs(graph, "JFK", temp, freq, tickets.size());
    }
};