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
    void preorder(TreeNode* root, vector<int>&res)
    {
        if(root == nullptr)
            return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);

    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        //preorder(root, res);
        stack<TreeNode*>st;
        
        if(root == nullptr)
            return res;
        
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            
            if(node ->right != nullptr)
                st.push(node->right);
            if(node ->left != nullptr)
                st.push(node->left);
        }
        
        return res;
    }
};