class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        int row =0, col = 0;
        int res = 0;
        while(row < n and col < n)
        {
            res =  res + mat[row][col] + mat[row][n-col-1];
            row++;
            col++;
        }
        if(n%2 == 1)
            res-=mat[n/2][n/2];
    return res;
    }
};