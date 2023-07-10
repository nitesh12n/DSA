class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int enclaves=0;
        queue<pair<int, int>>q;
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++)
        {
            for(int j=0; j<n;j++)
            {
                if((i == 0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1)
                {
                 q.push({i,j});   
                }
            }
        }
        vector<int>cordx = {0, -1, 0, 1};
        vector<int>cordy = {-1, 0, 1, 0};            
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            vis[i][j]=1;
            for(int k=0; k<4; k++)
            {
                int x = i + cordx[k];
                int y = j + cordy[k];
                if(x >=0 && x<m && y>=0 && y<n && grid[x][y] == 1 && vis[x][y] == 0)
                {
                    q.push({x,y});
                    vis[x][y] = 1;
                }
            }         
        }
        for(int i = 0; i<m; i++)
        {
            for(int j=0; j<n;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                enclaves++;
            }
        }
        return enclaves;        
    }
};