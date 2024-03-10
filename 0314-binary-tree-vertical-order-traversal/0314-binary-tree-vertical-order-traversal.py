# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        d = defaultdict(list)

        queue = [(root, 0, 0)]
    
        while queue:
            node, row, col = queue.pop(0)
            
            d[col].append(node.val)
            
            if node.left:
                queue.append((node.left, row + 1, col - 1))
            
            if node.right:
                queue.append((node.right, row + 1, col + 1))
                
        nd = dict(sorted(d.items()))
                
        return nd.values()
                
                
            
        
        
        