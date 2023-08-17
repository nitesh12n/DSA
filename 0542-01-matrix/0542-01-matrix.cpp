class Solution {
    vector<int>cordx = {0, -1, 0, 1};
    vector<int>cordy = {-1, 0, 1, 0};
    int isValid(int i, int j, int m, int n)
    {
        return i>=0 and i<m and j>=0 and j<n;
    }
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
            auto element = q.front();
            int i = element.first.first;
            int j = element.first.second;
            int d = element.second;
            q.pop();            
            dist[i][j] = d;
            
            for(int k=0; k<4; k++)
            {
                int x = i + cordx[k];
                int y = j + cordy[k];
                if(isValid(x, y, m, n) && vis[x][y] == 0)
                {
                    q.push({{x, y}, d + 1});
                    vis[x][y] = 1;
                }
            }          
        }
        
        return dist;
    }
};