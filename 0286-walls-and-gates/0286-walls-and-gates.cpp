class Solution {
    vector<int>deltaX = {0,-1,0,1};
    vector<int>deltaY= {-1,0,1,0};
    int isValid(int i, int j, int m, int n)
    {
        return i>=0 and i<m and j>=0 and j<n;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int INF = 2147483647;
        int m = rooms.size();
        int n = rooms[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        
        
        for(int i=0; i<m; i++)
        {
             for(int j=0; j<n; j++)
             {
                if(rooms[i][j] == 0)
                        q.push({{i,j}, 0});
             }  
        }        
        
        while(!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int i = cell.first.first;
            int j = cell.first.second;
            int dist = cell.second;
            if(rooms[i][j] == INF)
                rooms[i][j] = dist;
            for(int x=0; x < 4; x++)
            {
                int r = i + deltaX[x];
                int c = j + deltaY[x];

                if(isValid(r, c, m, n) and rooms[r][c] == INF)
                    q.push({{r, c}, dist + 1}); 
            }
        }          
    }
};