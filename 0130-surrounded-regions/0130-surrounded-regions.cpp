class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board)
    {
        vis[i][j] = 1;
        int m = board.size();
        int n = board[0].size();
        
        vector<int>cordx = {0, -1, 0, 1};
        vector<int>cordy = {-1, 0, 1, 0};
            
        for(int k=0; k<4; k++)
        {
            int x = i + cordx[k];
            int y = j + cordy[k];
            if(x >=0 && x<m && y>=0 && y<n && board[x][y] == 'O' && vis[x][y] == 0)
                dfs(x, y, vis, board);
        } 
        
    }
    void solve(vector<vector<char>>& board) {
        
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++)
        {
            if(board[i][0] == 'O')
                dfs(i, 0, vis, board);
            
            if(board[i][n-1] == 'O')
                dfs(i, n-1, vis, board);
        }
        
        for(int j = 0; j<n; j++)
        {   
            if(board[0][j] == 'O')
                dfs(0, j, vis, board);
            
            if(board[m-1][j] == 'O')
                dfs(m-1, j, vis, board);
        }
        
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(board[i][j] == 'O' && vis[i][j] ==0)
                    board[i][j] = 'X';
            }
        } 
    }
};