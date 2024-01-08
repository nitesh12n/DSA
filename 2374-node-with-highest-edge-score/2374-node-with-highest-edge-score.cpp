class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
       map<int, long>m; 
       for(int i = 0; i < edges.size(); i++)
           m[edges[i]]+= i;
        
        
       int maxScore = 0, res = -1;
       for(auto it : m)
       {
           if(it.second > maxScore)
           {
               maxScore = it.second;
               res = it.first;
           }
       }
       return res; 
    }
};