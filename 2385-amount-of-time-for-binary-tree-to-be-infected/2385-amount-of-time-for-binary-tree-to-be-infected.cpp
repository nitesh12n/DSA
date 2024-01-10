/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
     void createGraph(TreeNode* root, int parent, unordered_map<int, vector<int>>&adj)
     {         
         if(root == nullptr)
            return;
         
          if (adj.find(root->val) == adj.end())
                adj[root->val] = {};
          if(parent != -1)
                adj[root->val].push_back(parent);
          if(root->left)
                adj[root->val].push_back(root->left->val);    
          if(root->right)
                adj[root->val].push_back(root->right->val);        
         
         createGraph(root->left, root->val, adj);
         createGraph(root->right, root->val, adj);
     }
    
public:
    int amountOfTime(TreeNode* root, int start) {
                
        unordered_map<int, vector<int>>adj;
        createGraph(root, -1, adj);
        
        
        int res = -1;
        queue<int>q;
        unordered_set<int> vis;
        vis.insert(start);
        q.push(start);      
        while(!q.empty())
        {
            
            int neighbourCount = q.size();
            
            if(neighbourCount > 0)
                res++;         
            for(int i = 0; i < neighbourCount; i++)
            {
                auto node = q.front();
                q.pop();      
                for(auto neighbour : adj[node])
                {
                    if(vis.find(neighbour) == vis.end())
                    {
                        vis.insert(neighbour);
                        q.push(neighbour);
                    }
                }
            }
        }            
        return res;
    }
};