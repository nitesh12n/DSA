class Solution:
    
    
    
    def isValid(self, s: str) -> bool:
        
        st = []
        close = [')', '}', ']']
        mp = { ')' : '(',  '}' : '{', ']':'[' }
        
        for ch in s:
            
            if ch == '(' or ch == '{' or ch == '[':
                st.append(ch)
            elif len(st) > 0 and st[len(st) - 1] ==  mp[ch]:
                st.pop()
            else:
                return False
            
        return len(st) == 0
        