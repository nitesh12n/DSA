class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        
        freq = {}
        for num in arr:
            freq[num] = freq.get(num, 0) + 1
            
        num_set = set()
        
        for f in freq.values():
            
            if f in num_set:
                return False
            num_set.add(f)
            
        return True
            
            
            
        