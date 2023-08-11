class Solution {
    bool isSafe(int row, int col, int n, vector<string>&temp)
    {
        for(int i=0; i<col; i++)
        {
            if(temp[row][i] == 'Q')
                return false;
        }
        int i = row-1;
        for(int j = col-1; j>= 0 and i >= 0; j--)
        {
            if(temp[i][j] == 'Q')
                return false;
            i--;
        }
        i = row + 1; 
        for(int j = col-1; j>= 0 and i < n; j--)
        {
            if(temp[i][j] == 'Q')
                return false;
            i++;
        }
    return true;
    }
    void solve(int col, int n, vector<string>&temp, vector<vector<string>>&res)
    {
        if(col == n)
        {
            res.push_back(temp);
            return;
        }
        
        for(int row = 0; row < n; row++)
        {
            if(isSafe(row, col, n, temp))
            {
                temp[row][col] = 'Q';
                solve(col + 1, n, temp, res);
                temp[row][col] = '.';
            }
        }        
    }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
    vector<vector<string>>res;
    vector<string>temp(n, string(n,'.'));
        
    solve(0, n, temp, res);
        
    return res;
        
    }
};