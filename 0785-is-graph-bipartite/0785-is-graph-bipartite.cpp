class Solution {
private:
    bool areAllVisited(vector<int>&color)
    {
        for(auto i : color)
        {
            if (i == -1)
                return false;
        }
     return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size();
        
      vector<int>color(n,-1);
      
      queue<int>q;
        
      while(!areAllVisited(color))
      {    
          for(int i=0; i<n;i++)
          {
            if (color[i] == -1)
                {
                    q.push(i);
                    color[i] = 0;
                    break;
                }
          }
          while(!q.empty())
          {
              int node = q.front();
              q.pop();
              int c = color[node]^1;

              for(auto n:graph[node])
              {
                  if(color[n] == -1)
                  {
                      color[n] = c;
                      q.push(n);
                  }
                  else if(color[n] == color[node])
                      return false;
              } 
          }
      }
     return true;   
    }
};