class Solution {
private:

    bool dfs(vector<vector<int>>& graph, vector<int>&vis, vector<int>&path, int node, stack<int>&st)
    {
    vis[node]=1;
    path[node]=1;

        for(auto n : graph[node])
        {
            if(vis[n]==0)
            {
                if(dfs(graph, vis, path, n, st) == false)
                    return false;    
            }
            else if(path[n] == 1)
                return false;
        }
    st.push(node);
    path[node]=0;    
    return true;    
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
       vector<vector<int>>graph(numCourses);

       for(int i = 0; i<prerequisites.size();i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
       
       vector<int>vis(numCourses,0);
       vector<int>path(numCourses,0);    
	   stack<int>st;
	   vector<int>res;
        
	   for(int i = 0; i<numCourses;i++)
	   {
	        if(vis[i] == 0)
            {
                if(dfs(graph,vis,path,i,st) == false)
                    return {};
            }
           
	   }
	   
	   while(!st.empty())
	   {
	       res.push_back(st.top());
	       st.pop();
	   }
	 if(res.size() == numCourses)
         return res;
     return {};   
    }
};