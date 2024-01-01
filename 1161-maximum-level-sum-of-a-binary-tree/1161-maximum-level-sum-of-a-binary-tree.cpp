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
    int maxLevelSum(TreeNode* root) {
        
        
        queue<TreeNode*>q;
        q.push(root);
        int res = 0, maxSum = INT_MIN, level = 0;
        while(!q.empty())
        {
            int size = q.size();
            int levelSum = 0;
            level++;
            for(int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                levelSum+= node->val;
                
                if(node ->left)
                    q.push(node->left);
                if(node ->right)
                    q.push(node->right);
            }
            if(maxSum < levelSum)
            {
                maxSum = levelSum;
                res = level;
            }
        }
        return res;
    }
};