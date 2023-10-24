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
    vector<int> largestValues(TreeNode* root) {
        
        if(root == nullptr)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        
        while(!q.empty())
        {
            int  nodeCount = q.size();
            int rowMax = INT_MIN;
            for(int i = 0; i < nodeCount; i++)
            {
                auto node = q.front();
                q.pop();
                rowMax = max(rowMax, node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res.push_back(rowMax);
        }
        
    return res;
    }
};