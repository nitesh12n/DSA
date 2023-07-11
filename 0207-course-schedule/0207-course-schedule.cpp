class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>&vis, vector<int>&path, int node)
    {
        
        for(auto n : graph[node])
        {
            if(vis[n]==0)
            {
                vis[n]=1;
                path[n]=1;
                if(dfs(graph, vis, path, n) == false)
                    return false;    
                path[n]=0;
            }
            else if(path[n] == 1)
                return false;
        }
    return true;    
    }
    
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {   
        vector<vector<int>>graph(numCourses);

        for(int i = 0; i<prerequisites.size();i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

        vector<int>vis(numCourses, 0);
        vector<int>path(numCourses,0);    

        for(int i=0;i<numCourses;i++)
        {
            if(vis[i] == 0)
            {
                path[i] = 1;
                vis[i] = 1;
                if(dfs(graph,vis,path,i) == false)
                    return false;
                path[i]=0;
            }
        }
        
        return true;
    }
};