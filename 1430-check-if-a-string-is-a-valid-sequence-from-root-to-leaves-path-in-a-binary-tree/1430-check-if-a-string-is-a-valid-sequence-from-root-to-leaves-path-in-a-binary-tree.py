# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidSequence(self, root: Optional[TreeNode], arr: List[int]) -> bool:
        
        
        n = len(arr)
        def traverse(root, i):
            
            if not root or i == n:
                return False
            
            if root and not root.left and not root.right:
                return i == n - 1 and root.val == arr[i]
                        
        
            return root.val == arr[i] and (traverse(root.left, i + 1) or traverse(root.right, i + 1))
        
        return traverse(root, 0)
            
            
        