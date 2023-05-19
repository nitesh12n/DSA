class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>>q;
        
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();            
            dist[i][j] = d;
            vis[i][j] = 1;
            
            vector<int>cordx = {0, -1, 0, 1};
            vector<int>cordy = {-1, 0, 1, 0};
            
            for(int k=0; k<4; k++)
            {
                int x = i + cordx[k];
                int y = j + cordy[k];
                if(x >=0 && x<m && y>=0 && y<n && vis[x][y] == 0)
                {
                    q.push({{x, y}, d + 1});
                    vis[x][y] = 1;
                }
            }          
        }
        
        return dist;
    }
};