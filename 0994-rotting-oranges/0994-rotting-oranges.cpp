class Solution {
    vector<int>deltaX = {0, -1, 0, 1};
    vector<int>deltaY = {-1, 0, 1, 0};

    bool isValid(int r, int c, int m, int n)
    {
        return r>=0 and r<m and c>=0 and c<n;
    }
    int oranges(vector<vector<int>> grid, int m, int n)
    {
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0; i< m; i++)
        {
            for(int j=0; j< n; j++)  
            {
                if(grid[i][j] == 2)
                    q.push({{i, j}, 0});
            }
        }
        int res = 0;
        
        while(!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int time = cell.second;
            int row = cell.first.first;
            int col = cell.first.second;
            res = time;
            grid[row][col] = 2;
            for(int i=0; i <4; i++)
            {
                int r = row + deltaX[i];
                int c = col + deltaY[i];
                
                if(isValid(r, c, m, n) and grid[r][c] == 1)
                {
                    q.push({{r,c}, time + 1});
                    grid[r][c] = 2;
                    
                }
            }
        }
        for(int i=0; i< m; i++)
        {
            for(int j=0; j< n; j++)  
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
    return res;
        
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return oranges(grid, m, n);
        
    }
};