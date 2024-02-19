class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        m = {} 
        for s in strs:        
            key = str(sorted(s))
            
            if key in m:
                m[key].append(s)              
            else:
                m[key] = [s]
                
        return m.values()
            
            