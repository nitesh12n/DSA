"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        
        res = []
        def post(root):
            if root is None:
                return

            for child in root.children:
                post(child)

            res.append(root.val)
            return
        post(root)
        return res
        
        