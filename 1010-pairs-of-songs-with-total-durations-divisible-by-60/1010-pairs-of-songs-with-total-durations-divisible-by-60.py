class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        
        res = 0
        remainder = {}
        for l in time:  
            if l%60 == 0:
                res+= remainder.get(0, 0)
            else:
                res+= remainder.get(60 - l%60, 0)
            remainder[l%60] = remainder.get(l%60, 0) + 1
        return res
            
            
                
            
        
        
        