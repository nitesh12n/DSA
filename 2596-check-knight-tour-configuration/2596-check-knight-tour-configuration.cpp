class Solution {
    vector<vector<int>>moves = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    
    bool isValid(int row, int col, int n)
    {
        return row >= 0 and row < n and col>= 0 and col < n;
    }
    
    bool checkValidGrid(vector<vector<int>>& grid, int i, int j, int steps,  int n)
    {
        if(steps == n*n - 1)
            return true;
        for(auto move : moves)
        {
            int row = i + move[0];
            int col = j + move[1];
            if(isValid(row, col, n) and grid[row][col] == grid[i][j] + 1)
                return checkValidGrid(grid, row, col, steps + 1, n);
        }
        return false;
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        return checkValidGrid(grid, 0, 0, 0, grid.size());
    }
};