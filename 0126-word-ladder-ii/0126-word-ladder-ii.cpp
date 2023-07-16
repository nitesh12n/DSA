class Solution {
    private: 
    vector<vector<int>> getGraph(string beginWord, string endWord, vector<string>& wordList, int& startIndex, int& endIndex)
    {
        int words = wordList.size();

        for(int i=0;i<words;i++)
        {
            if(wordList[i]==beginWord)
                startIndex = i;
            else if (wordList[i] == endWord)
                endIndex=i;
        }
        if(endIndex==-1)
            return {};
        vector<vector<int>>adj(words);    
        
        for(int i=0; i<words;i++)
        {
            for(int j=i+1;j<words;j++)
            {
                if(getDiff(wordList[i], wordList[j]) == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        if(startIndex == -1)
        {
            adj.push_back({});
            startIndex = words;
            for(int i=0; i<words;i++)
            {
                if(getDiff(wordList[i], beginWord) == 1)
                {
                    adj[words].push_back(i);
                    adj[i].push_back(words);
                }
            }
        }
        return adj;
    }
    int getDiff(string s1, string s2)
    {
        int n = s1.size();
        int i=0,count=0;
        while(i<n)
        {
            if(s1[i]!=s2[i])
                count++;
            i++;
        }
        return count;
    }
   vector<int> getShortestPath(vector<vector<int>>adj, int src, int end)
   {
       int n = adj.size();
        vector<int>dist(n, INT_MAX);
       
       queue<int>q;
       q.push(src);
       dist[src]=0;
       
       while(!q.empty())
       {
           int node = q.front();
           q.pop();
           
           for(auto i : adj[node])
           {
               if(dist[i] == INT_MAX || dist[i] > dist[node]+1)
               {
                   dist[i] = dist[node]+1;
                   q.push(i);
               }
           }
       }
       return dist;
       
       
   }
void dfs(vector<string>& wordList, vector<vector<int>>&adj, vector<int>& dist, string beginWord, int startIndex, int node, vector<int>& temp, vector<vector<string>>&res)
{
    if(startIndex == node)
    {
        vector<string>row;
        for(int a = temp.size()-1; a>=0; a--)
        {
            if(temp[a]>=wordList.size())
                row.push_back(beginWord);
            else
                row.push_back(wordList[temp[a]]);
        }
        res.push_back(row);
        return;
    }
    
    for(auto i : adj[node])
    {
        if(dist[i] == dist[node] - 1)
        {
            temp.push_back(i);
            dfs(wordList, adj, dist, beginWord, startIndex, i, temp, res);
            temp.pop_back();
        }
    }
}

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int words = wordList.size();
        int startIndex= -1;
        int endIndex= -1;
        
        vector<vector<int>>adj = getGraph(beginWord, endWord, wordList, startIndex, endIndex);
        if(endIndex == -1)
            return {};
        
       vector<int>dist =  getShortestPath(adj, startIndex, endIndex);
       if(dist[endIndex] == INT_MAX)
           return {};
       
        vector<vector<string>>res;
        vector<int>temp;
        temp.push_back(endIndex);
        dfs(wordList, adj, dist, beginWord, startIndex, endIndex, temp, res);
        return res;
    }
};