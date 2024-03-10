# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        foundP, foundQ = False, False
        
        def find(node):
            nonlocal foundP
            nonlocal foundQ
            
            if not node:
                return None
            
            if node == p:
                foundP = True
            elif node == q:
                foundQ = True
                
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
        
        ans = find(root)
        
        if foundP and foundQ:    
            return ans
        
        return None