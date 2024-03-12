# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        
        
        diff = float('inf')
        res = 0
        def traverse(root):
            
            if not root:
                return
            nonlocal diff
            nonlocal res
            
            curr = abs(root.val - target)
            if curr < diff:
                diff = abs(root.val - target)
                res =  root.val
            elif curr == diff:
                res = min(res, root.val)
            
            if target < root.val:
                traverse(root.left)
            else:
                traverse(root.right)
                
        traverse(root)
        return res