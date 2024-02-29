# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import queue
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        
        q = queue.Queue()
        q.put(root)
        level = 0
        while not q.empty():
            
            size = q.qsize()  
            if level%2 == 0:
                prev = 0
                for i in range(size):
                    ele = q.get()
                    if ele.val %2 == 0 or prev >= ele.val:
                        return False
                    prev = ele.val
                    if ele.left:
                        q.put(ele.left)
                    if ele.right:
                        q.put(ele.right)
            else:
                prev = float('inf')
                for i in range(size):
                    ele = q.get()
                    if ele.val%2 != 0 or prev <= ele.val:
                        return False
                    prev = ele.val
                    if ele.left:
                        q.put(ele.left)
                    if ele.right:
                        q.put(ele.right)
            level+=1
            
        return True
                    
                    
                    
                
                
                
                
            
            
        
        