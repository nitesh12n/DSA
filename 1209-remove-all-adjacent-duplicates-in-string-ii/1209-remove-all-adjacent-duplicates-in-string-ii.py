class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        
        
        st = []
        
        
        for ch in s:
            
            if len(st) == 0 or st[-1][0] != ch:
                st.append((ch, 1))
                
            else:
                top, count = st[-1]
                
                if count + 1 == k:
                    st.pop()
                else:
                    st.pop()
                    st.append((ch, count + 1))
        
        
        res = ''.join(ch*count for ch, count in st)
        
        return str(res)
        
                
                
        