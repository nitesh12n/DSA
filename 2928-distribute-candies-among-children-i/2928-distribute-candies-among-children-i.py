class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        
        
        def recurse(index, curr):
            
            if index == 3:              
                return  curr == n
            
            ways = 0
            for i in range(limit + 1):
                ways+= recurse(index + 1, curr + i)
                
            return ways
        
        return recurse(0, 0)
                
                
            
            