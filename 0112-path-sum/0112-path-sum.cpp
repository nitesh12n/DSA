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
private: 
    bool pathSum(TreeNode* root, int targetSum)
    {
        if(root == nullptr)
            return false;
        if(root->left == nullptr and root->right==nullptr)
            return (targetSum-root->val)==0;
        
        return pathSum(root->left, targetSum-root->val) || pathSum(root->right, targetSum-root->val);
    
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr)
            return false;
        
        return pathSum(root, targetSum);
    }
};