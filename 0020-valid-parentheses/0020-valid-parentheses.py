class Solution:
    
    
    
    def isValid(self, s: str) -> bool:
        
        st = []
        openBracs = ['(', '{', '[']
        mp = { ')' : '(',  '}' : '{', ']':'[' }
        
        for ch in s:
            
            if ch in openBracs:
                st.append(ch)
            elif len(st) > 0 and st[len(st) - 1] ==  mp[ch]:
                st.pop()
            else:
                return False
            
        return len(st) == 0
        