class Solution {
    
    vector<int>topoSort(vector<vector<int>>&adj, set<char>& s)
    {
        vector<int> indegree(adj.size(), 0);
        queue<int> q;
        for(int i = 0; i < adj.size(); i++)
        {
            for(int p : adj[i])
                indegree[p]++;
        }

        for(int i =0;i<adj.size();i++)
            if(indegree[i]==0 and s.contains(i + 'a'))
                q.push(i);
        
        vector<int> res;
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            res.push_back(course);
            for(auto a : adj[course])
            {
                indegree[a]--;
                if(indegree[a] == 0)
                    q.push(a);
            }
        }
    return res;
    }
    
public:
    string alienOrder(vector<string>& words) {
        
        set<char>s;
        for(int i=0; i<words.size();i++)
        {
            for(auto ch: words[i])
                s.insert(ch);
        }
        
        
        vector<vector<int>>adj(26);
        for(int i=1; i<words.size();i++)
        {
            string s1 = words[i-1];
            string s2 = words[i];
            
            int j = 0, len = min(s1.size(), s2.size());
            
            for(j = 0; j < len; j++)
            {
              if(s1[j] != s2[j])
              {                
                  adj[s1[j]-'a'].push_back(s2[j]-'a');
                  break;
              }
            }
            if(s1.size() > s2.size() and j == len)
                return "";
            
        }
        vector<int> seq = topoSort(adj, s); 
        string res = "";

        if(seq.size() != s.size())
             return res;
        
        for(auto it : seq)
            res+= (it + 'a');
        return res;
        
    }
};