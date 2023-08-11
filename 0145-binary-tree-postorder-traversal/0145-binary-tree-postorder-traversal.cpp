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
    vector<int> postorderTraversal(TreeNode* root) {
     
        
        stack<TreeNode*> st;
        vector<int>res;
        
        if(root == nullptr)
            return {};
        st.push(root);
        
        while(!st.empty())
        {
            auto node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->left != nullptr)
                st.push(node->left);
            if(node->right != nullptr)
                st.push(node->right);            
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};