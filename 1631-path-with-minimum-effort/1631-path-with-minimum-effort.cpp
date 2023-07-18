class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int columns = heights[0].size();
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        
        vector<vector<int>>effort(rows, vector<int>(columns, 1e6));
        effort[0][0]=0;
        pq.push({0,{0,0}});
        
        vector<int>deltaX = {-1,0,1,0};
        vector<int>deltaY = {0,1,0,-1};
        while(!pq.empty())
        {
            auto data = pq.top();
            pq.pop();
            int eff = data.first;
            int x = data.second.first;
            int y=data.second.second;
            if(x==rows-1 && y==columns-1)
                return eff;
            for(int i=0;i<4;i++)
            {
                int newX = x+deltaX[i];
                int newY = y+deltaY[i];
                if(newX>=0 && newX<rows && newY>=0 && newY<columns)
                {
                    int eff = max(effort[x][y], abs(heights[newX][newY] - heights[x][y]));
                    if(effort[newX][newY] > eff)
                    {
                        effort[newX][newY] = eff;
                        pq.push({eff,{newX,newY}});
                    }
                }
            }
        }
        return effort[rows-1][columns-1];
    }
};