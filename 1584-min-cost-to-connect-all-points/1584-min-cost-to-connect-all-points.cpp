class UnionSet{

public:
    vector<int> parent;
    vector<int> rank;

    UnionSet(int size)
    {
        parent = vector<int>(size);
        rank = vector<int>(size);

        for(int i = 0; i<size; i++)
            {
             parent[i] = i;
             rank[i] = 0;       
            }       
    }
    int find(int i)
    {
        if(i == parent[i])
            return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }
    void doUnion(int i, int j)
    {
        int parent1 = find(i);
        int parent2 = find(j);

        if(parent1 != parent2)
        {
            if(rank[parent1] < rank[parent2])
                parent[parent1] = parent2;
            else if (rank[parent1] > rank[parent2])
                parent[parent2] = parent1;
            else
            {
                parent[parent1] = parent2;
                rank[parent2]++; 
            }
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<vector<int>> edges;
        int pointsSize = points.size();

        if(pointsSize <2)
         return 0;
        for(int point = 0; point < pointsSize; point++)
        {
            for(int i = point + 1; i< pointsSize; i++)
            {
                int mDistance = abs(points[point][0] - points[i][0])
                                 + abs(points[point][1] - points[i][1]);
                edges.push_back({mDistance, point, i});
            }      
        }
        sort(edges.begin(), edges.end());
        int edgesSize = edges.size();
        int edgesUsed = 0;
        
        UnionSet uset(pointsSize);
        
        int res = 0;
        for(int i = 0; i < edgesSize && edgesUsed < pointsSize - 1; i++)
        {
            int distance = edges[i][0];
            int point1 = edges[i][1];
            int point2 = edges[i][2];
           
            if(uset.find(point1) != uset.find(point2))
            {
               res+=distance;
               uset.doUnion(point1, point2);  
               edgesUsed++;       
            }

        }
    return res;
    }
};