class Solution {
public:
        void visitElement(vector<vector<char>>& grid, vector<vector<int>>& visited, queue<pair<int, int>>& q, int nrow, int ncol)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == '1'
                       && visited[nrow][ncol] == 0)
                    {
                        q.push(make_pair(nrow, ncol));
                        visited[nrow][ncol] = 1;
                    }
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int row, int col)
    {
        visited[row][col] = 1;
       
        
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            visitElement(grid, visited, q, r -1, c);
            visitElement(grid, visited, q, r, c-1);
            visitElement(grid, visited, q, r + 1, c);
            visitElement(grid, visited, q, r, c + 1);

        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<int>>visited(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {   
              if(grid[i][j] == '1' && visited[i][j] == 0)
              {
                  res++;
                  bfs(grid, visited, i, j);
              }
            }
        }
    return res;
    }
};