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
public:
    void paths(TreeNode* root, string s, vector<string>& res)
    {
        if(root == nullptr)
            return;
        
        s+= to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            res.push_back(s);
            return;
        }
        
        s+="->";
        paths(root->left, s, res);
        paths(root->right, s, res);
        

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        paths(root, "", res);
        return res;
    }
};