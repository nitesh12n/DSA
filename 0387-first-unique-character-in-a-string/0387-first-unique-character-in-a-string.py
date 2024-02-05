class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        
        m = {}
        for i in range(len(s)):
            m[s[i]] = m.get(s[i], 0) + 1
            
        for i in range(len(s)):
            if m[s[i]] == 1:
                return i
        return -1
        
            
            
            
        