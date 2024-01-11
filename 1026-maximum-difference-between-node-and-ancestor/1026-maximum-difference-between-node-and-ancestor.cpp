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
    
    int maxAncestorDiff(TreeNode* root, int maxi, int mini)
    {
        if(!root)
            return maxi - mini;
        
        maxi = max(maxi, root->val);
        mini = min(mini, root->val);
        
        int l = maxAncestorDiff(root->left, maxi, mini);
        int r = maxAncestorDiff(root->right, maxi, mini);

        return max(l, r);
    }
    
    
public:
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiff(root, INT_MIN, INT_MAX);
    }
};