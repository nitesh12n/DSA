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
    void kthSmallest(TreeNode* root, int& k, int& res)
    {
        if(root == nullptr)
            return;

        kthSmallest(root->left, k, res);
        k--;
        if(k==0)
            res = root->val;
        kthSmallest(root->right, k, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int res = 0;
        kthSmallest(root, k, res);
        return res;
    }
};