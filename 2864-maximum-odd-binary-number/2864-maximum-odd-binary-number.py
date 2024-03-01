class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        
        
        count = 0
        for ch in s:
            count+= ch =='1'
        size = len(s)  

        res = '1'*(count -1) +  '0'*(size - count) + '1'
        return res
        
        