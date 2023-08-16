class Solution {
    vector<int> deltaX = {0,-1,0,1};
    vector<int> deltaY = {-1,0,1,0};
    bool isValid(int i, int j, int m, int n)
    {
        return i>=0 and i<m and j>=0 and j<n;
    }
    
    void pacificAtlantic(vector<vector<int>>& heights, vector<vector<int>>& vis, int i, int j)
    {
        int m = heights.size(), n = heights[0].size();        
        
        vis[i][j] = 1;
        for(int x=0; x < 4; x++)
        {
            int r = i + deltaX[x];
            int c = j + deltaY[x];
            
            if(isValid(r,c, m, n) and heights[r][c] >= heights[i][j] and vis[r][c] == 0)
               pacificAtlantic(heights, vis, r, c);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>>pacific(m, vector<int>(n, 0));
        vector<vector<int>>atlantic(m, vector<int>(n, 0));
        vector<vector<int>>res;
        for(int i=0; i<m; i++)
        {
            pacificAtlantic(heights, pacific, i, 0);
            pacificAtlantic(heights, atlantic, i, n-1);
        }
        for(int j=0; j<n; j++)
        {
            pacificAtlantic(heights, pacific, 0, j);
            pacificAtlantic(heights, atlantic, m-1, j);
        }
        
        for(int i=0; i<m; i++)
        {
          for(int j=0; j<n; j++)
          {
              if(atlantic[i][j] == 1 and pacific[i][j] == 1)
                  res.push_back({i, j});
          }
        }
    return res;
    }
};