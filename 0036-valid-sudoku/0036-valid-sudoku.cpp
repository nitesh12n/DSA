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
       
        //validate rows  
        int n = 9;
        for(int i = 0; i < 9; i++)
        {
            vector<int>count(n+1, 0);
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.' and ++count[board[i][j] - '0'] > 1)
                    return false;            
            }
        }
        //validate columns  
        for(int i = 0; i < 9; i++)
        {
            vector<int>count(n+1, 0);
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.' and ++count[board[j][i] - '0'] > 1)
                    return false;            
            }
        }
        
        //validate 3x3 
        for(int i = 0; i < n; i+=3)
        {
            for(int j = 0; j < n; j+=3)
            {
                if(validate(board, i, j) == false)
                    return false;    
            }
        }
        
        return true;
    }
};