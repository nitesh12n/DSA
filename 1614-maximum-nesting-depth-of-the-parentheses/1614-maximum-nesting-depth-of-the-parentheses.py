class Solution:
    def maxDepth(self, s: str) -> int:
        
        res = 0
        openB = 0
        for ch in s:
            
            if ch == '(':
                openB+=1
            elif ch == ')':
                openB-=1
            
            res = max(res, openB)
            
        return res
                
                
            
        
        