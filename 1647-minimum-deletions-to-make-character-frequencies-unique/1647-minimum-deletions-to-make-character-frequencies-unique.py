class Solution:
    def minDeletions(self, s: str) -> int:
        m1 = defaultdict(int)
        
        for char in s:
            m1[char] += 1
            
        m2 = {}
        
        ans = 0
        for key, val in m1.items():
            if val not in m2:
                m2[val] = key
            else:
                while val in m2 and val > 0:
                    ans += 1
                    val -= 1
                m2[val] = key
            
                
        return ans
                