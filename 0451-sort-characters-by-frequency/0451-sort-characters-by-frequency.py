class Solution:
    def frequencySort(self, s: str) -> str:
        
        freq = Counter(s)
        
        freqArray = [(f, ch) for ch, f in freq.items()]
        freqArray.sort(key= lambda x:x[0], reverse=True)     
        
        res = ''.join(count*ch for ch, count in freqArray)
        return res
        
    