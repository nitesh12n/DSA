
class UnionSet {
   
    vector<int>parent;
    vector<int>rank;
    
    public:
    
    UnionSet(int size)
    {
        for(int i = 0; i < size; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
    int Find(int i)
    {
        if(parent[i] != i)
            return parent[i] = Find(parent[i]);
        return i;
    }
    
    bool Union(int i, int j)
    {
        int p1 = Find(i);
        int p2 = Find(j);
        if(p1 == p2)
            return false;
        
        if(rank[p1] < rank[p2])
            parent[p1] = p2;
        
        else if(rank[p2] < rank[p1])
            parent[p2] = p1;
        
        else
        {
            parent[p1] = p2;
            rank[p2]++;
        }
    return true;
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        UnionSet us = UnionSet(1001);
        
        for(auto edge : edges)
        {
            if(!us.Union(edge[0], edge[1]))
                return {edge[0], edge[1]}; 
        }
    return {};
    }
};
