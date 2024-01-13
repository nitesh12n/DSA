class Solution:
    def minSteps(self, s: str, t: str) -> int:
        
        freq = {}
        
        
        for ch in s:
            freq[ch] = freq.get(ch, 0) + 1
            
        for ch in t:
            freq[ch] = freq.get(ch, 0) - 1
            
        res = 0
        for ch, fr  in freq.items():
            
            if fr > 0:
                res+= fr
        return res
            