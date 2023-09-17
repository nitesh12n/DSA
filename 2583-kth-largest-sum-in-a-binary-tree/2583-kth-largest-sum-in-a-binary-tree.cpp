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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*>q;
        priority_queue<long, vector<long>, greater<long>>pq;
        q.push(root);
        int level = 0;
        
        while(!q.empty())
        {
            int count = q.size();
            long sum = 0;
            while(count--)
            {
                auto node = q.front();
                sum+= node->val;
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            pq.push(sum);
            if(pq.size() > k)
                pq.pop();
            level++;
        }
        return pq.size() < k ? -1 : pq.top();
    }
};