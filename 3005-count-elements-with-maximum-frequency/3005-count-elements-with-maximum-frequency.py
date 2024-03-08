from collections import defaultdict

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mapp = defaultdict(int)
        
        for num in nums:
            mapp[num] += 1
            
        maxFreq = -1e9
        
        for val in mapp.values():
            maxFreq = max(maxFreq, val)
            
        ans = 0
        
        for val in mapp.values():
            if val == maxFreq:
                ans += val
        
        return ans
    