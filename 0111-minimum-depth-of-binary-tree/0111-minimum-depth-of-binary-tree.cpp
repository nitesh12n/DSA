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
    int minD(TreeNode* root)
    {
         if(root==nullptr)
            return 1e7;
        if(root->left == nullptr and root->right==nullptr)
            return 1;
        
        return 1 + min(minD(root->left), minD(root->right));
    }
public:
    int minDepth(TreeNode* root) {
        
        int res = minD(root);
        if(res == 1e7)
            return 0;
        return res;
    }
};