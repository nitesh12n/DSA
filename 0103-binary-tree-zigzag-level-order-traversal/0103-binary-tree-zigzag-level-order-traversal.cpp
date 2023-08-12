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
         
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                
        vector<vector<int>>res;
        queue<TreeNode*>q;
        
        if(root == nullptr)
            return res;
        
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            res.push_back(vector<int>(size));
            for(int i=0; i <size; i++)
            {
                auto node = q.front();
                q.pop();
                if(node ->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);         
                if(level%2 == 0)
                    res[level][i] = node->val;
                else
                    res[level][size-i-1] = node->val;
            }
            level++;
        }
    return res;
    }
};