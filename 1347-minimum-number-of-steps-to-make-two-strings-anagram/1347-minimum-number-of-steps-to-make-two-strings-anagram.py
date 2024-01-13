class Solution:
    def minSteps(self, s: str, t: str) -> int:
        
        freqS = {}
        freqT = {}
        
        
        for ch in s:
            if freqS.get(ch) is None:
                freqS[ch] = 1
            else:    
                freqS[ch]+=1
        for ch in t:
            if freqT.get(ch) is None:
                freqT[ch] = 1
            else:    
                freqT[ch]+=1
            
        res = 0
        for ch, freq  in freqS.items():
            
            if freqT.get(ch) is None:
                res+= freq
            elif freq > freqT.get(ch):
                res+= freq - freqT[ch]
        return res
            