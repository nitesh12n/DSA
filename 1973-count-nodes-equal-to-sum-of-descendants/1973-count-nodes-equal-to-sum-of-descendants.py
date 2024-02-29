# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        
        
        res = 0
        
        
        def countNodes(root):
            nonlocal res
            if root is None:
                return 0
            
            left = countNodes(root.left)
            right = countNodes(root.right)
            
            if left + right == root.val:
                res+=1
            
            return left + right + root.val
        
        countNodes(root)
        return res