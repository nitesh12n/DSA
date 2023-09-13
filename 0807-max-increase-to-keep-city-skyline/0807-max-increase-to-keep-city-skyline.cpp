class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
       
        int n = grid.size();
        vector<int>rowMax(n, 0);
        vector<int>columnMax(n, 0);
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                columnMax[j] = max(columnMax[j], grid[i][j]);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                res+= min(rowMax[i], columnMax[j]) - grid[i][j];
        }
        return res;
    }
};