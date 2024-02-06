class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        m = {}
        
        
        for s in strs:
            
            key = ''.join(sorted(s))
            
            if key not in m:
                m[key] = [s]
            else:
                m[key].append(s)
                
        res = []
        for key in  m:
            res.append(m[key])
            
        return res
            
            