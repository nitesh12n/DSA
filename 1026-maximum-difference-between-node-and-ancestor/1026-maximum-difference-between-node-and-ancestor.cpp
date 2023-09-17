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
    pair<int,int> maxDiff(TreeNode* root, int& res)
    {
        if(!root)
            return {INT_MAX, INT_MIN};
        
        
        auto l = maxDiff(root->left, res);
        auto r = maxDiff(root->right, res);
        
        if(l.first != INT_MAX or r.first != INT_MAX)
            res = max(res, abs(root->val - min(l.first,r.first)));
        if(l.second != INT_MIN or r.second != INT_MIN)
            res = max(res, abs(root->val - max(l.second,r.second)));
        
        return {min(root->val, min(l.first, r.first)), max(root->val, max(l.second, r.second))};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        maxDiff(root, res);
        return res;
    }
};