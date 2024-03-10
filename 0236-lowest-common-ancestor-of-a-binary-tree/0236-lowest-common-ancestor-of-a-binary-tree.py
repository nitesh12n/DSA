# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def find(node):
            if not node:
                return None
            
            left = find(node.left)
            
            right = find(node.right)
            
            if left and right:
                return node
            
            if left or right:
                if node.val == p.val or node.val == q.val:
                    return node
                else:
                    return left if left else right
                
            if not left and not right:
                if node.val == p.val or node.val == q.val:
                    return node
                
            return None
        
        return find(root)
