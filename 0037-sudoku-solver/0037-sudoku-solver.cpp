class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char ch)
    {
        //row
        for(int i = 0; i< board.size(); i++)
        {
            if(board[row][i] == ch)
                return false;
        }
        //column
        for(int i = 0; i< board.size(); i++)
        {
            if(board[i][col] == ch)
                return false;
        }
        //3x3
        int r = (row/3)*3;
        int c = (col/3)*3;
        for(int i = r ; i< r +3; i++)
        {
            for (int j = c; j < c+3; j++)
            {
                if(i != row && j != col && board[i][j] == ch)
                    return false;
            }
        }
    return true;
    }
    bool solveSudokuAux(vector<vector<char>>& board, int row)
    {

        for(int i = row; i < board.size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(isValid(board, i, j , c))
                        {
                            board[i][j] = c;
                            bool isSolved = solveSudokuAux(board, i);
                            if(isSolved)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuAux(board, 0);
    }
};