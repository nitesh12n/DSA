/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    void KDistanceChildren(TreeNode* root, int k, vector<int>&res)
    {
        if( k==0 and root)
        {    
            res.push_back(root->val);
            return;
        }
        
        if( k < 0 || root == nullptr)
            return;
        
                
     
        KDistanceChildren(root->left, k-1, res);
        KDistanceChildren(root->right, k-1, res);
    }
    
    int distance(TreeNode* root, int target, int k, vector<int>&res)
    {
        if(root == nullptr)
            return -1;
        
        if(root->val == target)
        {
            KDistanceChildren(root, k, res);
            return 0;
        }
        
        
        int l = distance(root->left, target, k, res);
        if(l != -1)
        {
            if(l + 1 == k)
                res.push_back(root->val);
            else 
                KDistanceChildren(root->right, k-l-2, res);  
            
            return l + 1;
        }
        int r = distance(root->right, target, k, res);
        
        if(r != -1)
        {
            if(r + 1 == k)
                res.push_back(root->val);
            else
                KDistanceChildren(root->left, k-r-2, res); 
            
            return r + 1;
        }
        
    return -1;
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>res;
        distance(root, target->val, k, res);  
        return res;
    }
};