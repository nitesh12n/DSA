class Solution:
    def customSortString(self, order: str, s: str) -> str:
        
        res = []        
        st2 = Counter(s) 
        for ch in order:
            
            if ch in s:
                res.append(st2[ch]*ch)
                st2[ch] = 0
        
        for key, value in st2.items():
            
            if value > 0:
                res.append(value*key)
                
        return ''.join(res)
                
            
            