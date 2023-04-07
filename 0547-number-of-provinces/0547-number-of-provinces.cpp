class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int node)
    {
        visited[node] = 1;
        for(int i = 0; i < isConnected.size(); i++)
        {
            if(isConnected[node][i] == 1 and node != i and visited[i] == 0)
                dfs(isConnected, visited, i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int> visited(isConnected.size(), 0);
        int provinces = 0;
        for(int i = 0; i < isConnected.size(); i++)
        {
            if (visited[i] == 0)
            {
                provinces++;
                dfs(isConnected, visited, i);
                
            }
        }
    return provinces;
    }
};