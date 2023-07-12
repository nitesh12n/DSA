class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses, 0);
        vector<int>res;
        queue<int>q;

        for(int i = 0; i<prerequisites.size();i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        for(int i =0; i<numCourses;i++)
        {
            for(auto n : graph[i])
                indegree[n]++;
        }
        
        for(int i =0; i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto i : graph[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        if(res.size()==numCourses)
            return res;
        return {};
        
    }
};