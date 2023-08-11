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
    int sumNumbers(TreeNode* root, int num)
    {
        if(root == nullptr)
           return 0;
        if(root ->left == nullptr and root->right == nullptr)
            return num*10 + root->val;
        

        
       num = num*10 + root->val; 
        
       int left = sumNumbers(root->left, num);
       int right= sumNumbers(root->right, num);
        
        return left + right;
    }
public:
    int sumNumbers(TreeNode* root) {
        
        return sumNumbers(root, 0);
    }
};