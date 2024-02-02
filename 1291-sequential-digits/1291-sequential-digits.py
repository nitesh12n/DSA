class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        
        res = []
          
        def seqNumber(num):
            
            
            if num >= low and num <= high:
                res.append(num)
            
            if num%10 == 9:
                return
            
            seqNumber(num*10 + num%10 + 1)
            
        
        
        for i in range(1, 10):
            seqNumber(i)
        res.sort()
        return res
    
            
            
        