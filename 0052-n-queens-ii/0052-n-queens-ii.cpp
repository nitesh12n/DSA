class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n)
    {
        //row check
        for( int i = 0; i< col; i++)
        {
            if(board[row][i] == 'Q')
                return false;
        }
        //upper diagonal
        int r = row-1, c = col-1;
        while(r >=0 && c >=0)
        {
            if(board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        //lower diagonal
        r = row+1, c = col-1;
        while(r <n && c >=0)
        {
            if(board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }
    return true;
    }

    int solveNQueens(vector<string>& board, int col, int n)
    {
        if(col == n) 
            return 1;
        int count = 0;
        for(int row = 0; row < n; row++)
        {
            if(isSafe(board, row, col, n))
            {
            board[row][col] = 'Q';
            count+= solveNQueens(board, col + 1, n);
            board[row][col] = '.';
            }  
        }

        return count;
    }

    int totalNQueens(int n) {
         string s(n, '.');
       vector<string> board(n, s);
       return solveNQueens(board, 0, n);
    }
};