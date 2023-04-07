class Solution {
public:
      void visitElement(vector<vector<int>>& grid, vector<vector<int>>& visited, queue<pair<int, int>>& q, int nrow, int ncol)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1
                       && visited[nrow][ncol] == 0)
                    {
                        q.push(make_pair(nrow, ncol));
                        visited[nrow][ncol] = 1;
                        
                    }
    }
    
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int& res)
    {        
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {   
              if(grid[i][j] == 2 && visited[i][j] == 0)
              {
                 q.push(make_pair(i, j));
                 visited[i][j] = 1;
              }
            }
        }
        
        q.push(make_pair(-1, -1));
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r == -1 and c == -1)
            {
                if (!q.empty())
                {
                    q.push(make_pair(-1, -1));
                    res++;   
                }
            }
            else
            {
                visitElement(grid, visited, q, r -1, c);
                visitElement(grid, visited, q, r, c-1);
                visitElement(grid, visited, q, r + 1, c);
                visitElement(grid, visited, q, r, c + 1);
            }
            

        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {   
              if(grid[i][j] == 1 && visited[i][j] == 0)
                res = -1;
            }
        }
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>>visited(m, vector<int>(n, 0));
        bfs(grid, visited, res);
        
    return res;
    }
};