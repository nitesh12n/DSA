class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int color)
    {
        
        image[sr][sc] = color;
        
        int m = image.size();
        int n = image[0].size();
        
        if (sr-1 >=0 and image[sr-1][sc] == oldColor)
            dfs(image, sr-1, sc, oldColor, color);
        if (sc-1 >=0 and image[sr][sc-1] == oldColor)
            dfs(image, sr, sc-1, oldColor, color);
        if (sc+1 <n and image[sr][sc+1] == oldColor)
            dfs(image, sr, sc+1, oldColor, color);
        if (sr+1 <m and image[sr+1][sc] == oldColor)
            dfs(image, sr+1, sc, oldColor, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if ( image[sr][sc] != color)
            dfs(image, sr, sc, image[sr][sc], color);
        
        return image;
    }
};