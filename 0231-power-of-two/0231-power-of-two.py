class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        
        count = 0
        
        if n <= 0:
            return False
        
        while n > 0:
            
            count+= n&1
            
            if count == 2:
                return False
            n = n>>1;
        return True
        