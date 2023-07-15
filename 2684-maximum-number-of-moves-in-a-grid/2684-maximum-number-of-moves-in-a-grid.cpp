class Solution {
private:
    int maxMoves(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp)
    {
        int m = grid.size();
        int n=grid[0].size();
        
        if(col+1==n || row<0 || row==m)
            return 0;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int u=0,r=0,d=0;
        
        //up-right
        if(row-1>=0 and grid[row-1][col+1]>grid[row][col])
            u = maxMoves(grid, row-1,col+1, dp)+1;
        //right
        if(row>=0 and row<m and grid[row][col+1]>grid[row][col])
            r = maxMoves(grid, row,col+1, dp)+1;
        //down-right
        if(row+1<m and grid[row+1][col+1]>grid[row][col])
            d = maxMoves(grid, row+1,col+1, dp)+1;
        
      return dp[row][col]=max(u,max(r,d));  
    }
    
    
public:
    
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
            res = max(res, maxMoves(grid,i,0, dp));
        return res;
    }
};