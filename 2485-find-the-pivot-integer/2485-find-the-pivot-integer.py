class Solution:
    def pivotInteger(self, n: int) -> int:
        
        total = n*(n + 1)//2
        
        curr = 0
        print(total)
        for i in range(1,n + 1):
            
            if curr + i == total - curr:
                return i
            curr+= i
            
        return -1
            
        