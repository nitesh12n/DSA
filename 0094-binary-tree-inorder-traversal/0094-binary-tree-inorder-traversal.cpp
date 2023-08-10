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
    void inorder(TreeNode*root, vector<int>& res)
    {
        if(root == nullptr)
            return;
        
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>res;
        //inorder(root, res);
        if(root == nullptr)
            return res;
        stack<TreeNode*>s;
        
        TreeNode* current = root;
        while(!s.empty() or current)
        {
            while(current)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            res.push_back(current->val);
            current = current->right;
        }
        
        return res;
    }
};