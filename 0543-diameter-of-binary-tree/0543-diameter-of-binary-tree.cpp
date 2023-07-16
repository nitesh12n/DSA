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
    int diameterOfBinaryTree(TreeNode* root, int& maxDia)
    {
        if(root==nullptr)
            return 0;
        
        int l = diameterOfBinaryTree(root->left, maxDia);
        int r = diameterOfBinaryTree(root->right, maxDia);
        maxDia = max(maxDia, l+r);
        
        return max(l,r)+1;
        
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==nullptr)
            return 0;
    int maxDia=0;
    diameterOfBinaryTree(root, maxDia); 
    return maxDia;
    }
};