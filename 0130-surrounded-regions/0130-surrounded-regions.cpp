class Solution {
    vector<int> deltaX = {0,-1,0,1};
    vector<int> deltaY = {-1,0,1,0};
    bool isValid(int i, int j, int m, int n)
    {
        return i>=0 and i<m and j>=0 and j<n;
    }
    void dfs(vector<vector<char>>& board, vector<vector<int>>&vis, int i, int j)
    {
        if(board[i][j] != 'O' or vis[i][j] == 1)
            return;

        int m = board.size(), n = board[0].size();
        vis[i][j] = 1;
        for(int x=0; x < 4; x++)
        {
            int r = i + deltaX[x];
            int c = j + deltaY[x];
            
            if(isValid(r, c, m, n) and board[r][c] == 'O' and vis[r][c] == 0)
                dfs(board, vis, r, c);             
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size(), n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        
        //top row
        for(int j=0; j<n; j++)
            dfs(board, vis, 0,j);
        //bottom row
        for(int j=0; j<n; j++)
            dfs(board, vis, m-1,j);
        //left column
        for(int i=1; i<m-1; i++)
            dfs(board, vis, i,0);
        //right column
        for(int i=1; i<m-1; i++)
            dfs(board, vis, i,n-1);
        
        for(int i=0; i<m; i++)
        {
          for(int j=0; j<n; j++)
          {
              if(board[i][j] == 'O' and vis[i][j] == 0)
                  board[i][j] = 'X'; 
          }
        }
    }
};