class Solution {
    vector<int>rowD={0,-1,0,1};
    vector<int>colD={-1,0,1,0};
    
    bool isValidCell(int row, int col, int m, int n)
    {
        return row >=0 and row < m and col >=0 and col < n;
    }
        
    bool exist(vector<vector<char>>& board, string word, int index, int row, int col, vector<vector<int>>& vis)
    {
         if(index == word.size())
            return true;
        
        if(word[index] != board[row][col])
            return false;
        if(index+1 == word.size())
            return true;
        
        int m  = board.size();
        int n = board[0].size();
                
        for(int i = 0; i<4;i++)
        {
            int r = row + rowD[i];
            int c = col + colD[i];
            if(isValidCell(r, c, m, n) and vis[r][c] == 0)
            {
                vis[r][c] = 1;
                if(exist(board, word, index+1, r, c, vis))
                    return true;
                vis[r][c] = 0;
            }
        }
     return false;  
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m  = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        
        for(int i = 0;i<m;i++)
        {
           for(int j = 0;j<n;j++)
            {
               vis[i][j] = 1;
                if(board[i][j] == word[0] and exist(board, word, 0, i, j, vis))
                    return true;
               vis[i][j] = 0;
            } 
        }
    return false;
    }
};