class Solution {
    
    bool validate(vector<vector<char>>& board, int row, int col)
    {
        int n = 9;
        vector<int>count(n+1, 0);
        for(int i = row; i <= row + 2; i++)
        {
            for(int j = col; j <= col+2; j++)
            {
                if(board[i][j] != '.' and ++count[board[i][j] - '0'] > 1)
                    return false;
            }
       }
    return true;
    }
public:

    bool isValidSudoku(vector<vector<char>>& board) {
       
        //validate rows and columns  
        for(int i = 0; i < 9; i++)
        {
            vector<int>rows(10, 0);
            vector<int>columns(10, 0);
            
            for(int j = 0; j < 9; j++)
            {
                //rows
                if(board[i][j] != '.' and ++rows[board[i][j] - '0'] > 1)
                    return false;
                //columns
                if(board[j][i] != '.' and ++columns[board[j][i] - '0'] > 1)
                    return false;  
            }
        }
        
        //validate 3x3 
        for(int i = 0; i < 9; i+=3)
        {
            for(int j = 0; j < 9; j+=3)
            {
                if(validate(board, i, j) == false)
                    return false;    
            }
        }
        
        return true;
    }
};