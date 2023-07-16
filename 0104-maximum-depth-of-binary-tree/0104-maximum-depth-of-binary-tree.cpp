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
    int maxDepth(TreeNode* root, int& maxD)
    {
        if(root==nullptr)
            return 0;
        
        int l = maxDepth(root->left, maxD);
        int r = maxDepth(root->right, maxD);
        
        return maxD = max(l, r) + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        
        int maxD=0;
        maxDepth(root, maxD); 
        return maxD;
    }
};