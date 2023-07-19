class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        vector<int>deltaX = {0,-1,0,1};
        vector<int>deltaY= {-1,0,1,0};
        int row = grid.size();
        int col = grid[0].size();
        int res=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int d=0;d<4;d++)
                    {
                        int newR =i+deltaX[d];
                        int newC = j+deltaY[d];
                        if(newR>=0 and newR<row and newC>=0 and newC<col)
                        {
                            if(grid[newR][newC]==0)
                                res++;
                        }
                        else 
                            res++;           
                    }
                }
            }
        }
        return res;
    }
};