# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: TreeNode, p: TreeNode) -> Optional[TreeNode]:
        # if not p.left and not p.right:
        #     return None
        
        
        def inorder(root):
            
            if root is None:
                return root
            
            left = inorder(root.left)
            
            if left is not None:
                return left
            
            if root.val > p.val:
                return root
            
            return inorder(root.right)
        
        return inorder(root)
        
        