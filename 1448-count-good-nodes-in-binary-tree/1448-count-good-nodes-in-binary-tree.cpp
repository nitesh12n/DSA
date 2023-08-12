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
    int goodNodes(TreeNode* root, int pathMax)
    {
        if(root == nullptr)
            return 0;
        
        int count = 0;
        if(root->val >= pathMax)
            count = 1;
        pathMax = max(pathMax, root->val);
        
        int left = goodNodes(root->left, pathMax);
        int right = goodNodes(root->right, pathMax);
        
    return left + right + count;
    }
public:
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return goodNodes(root, root->val);
    }
};