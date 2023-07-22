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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        TreeNode* root=nullptr;
        
        if(root1 != nullptr and root2!=nullptr)
            root = new TreeNode(root1->val+root2->val);
        else if (root1!= nullptr)
            return root1;
        else if (root2!=nullptr)
            return root2;    
        
        if(root!= nullptr)
        {   
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
        }
        
    return root;
    }
};