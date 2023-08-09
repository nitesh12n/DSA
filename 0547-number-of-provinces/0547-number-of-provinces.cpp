class Solution {
    void dfs(vector<vector<int>>& isConnected, int i, vector<int>& vis)
    {
        vis[i] = 1;
        
        for(int j=0; j < isConnected.size(); j ++)
        {
            if(isConnected[i][j] == 1 and vis[j] == 0)
                dfs(isConnected, j, vis);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
       int n = isConnected.size(), res=0;
        vector<int>vis(n, 0);
        
        for(int i= 0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                res++;
                dfs(isConnected, i, vis);
            }
        }
    return res;
    }
};