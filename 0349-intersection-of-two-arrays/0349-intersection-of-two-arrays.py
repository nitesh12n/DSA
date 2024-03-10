class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        st = set()
        for num in nums1:
            st.add(num)
        
        res = set()
        for num in nums2:
            
            if num in st:
                res.add(num)
        
        return res
            
            
            
            
            