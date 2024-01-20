class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        
        st = []
        for i in range(0, len(heights)):
            
            while len(st) > 0 and heights[i] >= heights[st[-1]]:
                st.pop()
            
            st.append(i)
        return st
            
            
            