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
    
    void leftBoundary(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr)
            return;
        if(root ->left == nullptr and root->right == nullptr)
            return;
        
        res.push_back(root->val);
        leftBoundary(root->left, res);
        if(!root->left)
            leftBoundary(root->right, res);
    }
    void rightBoundary(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr)
            return;
        if(root ->left == nullptr and root->right == nullptr)
            return;
        
        res.push_back(root->val);
        rightBoundary(root->right, res);
        if(!root->right)
            rightBoundary(root->left, res);
    }
    void getLeaves(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr)
            return;
        if(root ->left == nullptr and root->right == nullptr)
        {
            res.push_back(root->val);
            return;
        }
        
        getLeaves(root->left, res);
        getLeaves(root->right, res);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        vector<int>res;
        vector<int>rightRes;
        res.push_back(root->val);
        
        leftBoundary(root->left, res);
        getLeaves(root->left, res);
        getLeaves(root->right, res);
        rightBoundary(root->right, rightRes);
        
        for(int i = rightRes.size() -1 ; i>=0; i--)
            res.push_back(rightRes[i]);
        return res;
    }
};