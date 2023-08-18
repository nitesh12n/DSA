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
    void findBottomLeftValue(TreeNode* root, int level, int& maxLevel, int& res)
    {
        if(root == nullptr)
            return; 
        
        if(level > maxLevel)
        {
            res = root->val;
            maxLevel = level;
        }
        
        findBottomLeftValue(root->left, level + 1, maxLevel, res);
        findBottomLeftValue(root->right, level + 1, maxLevel, res);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        
        int res;
        int maxLevel = -1;
        findBottomLeftValue(root, 0, maxLevel, res);
        return res;
    }
};