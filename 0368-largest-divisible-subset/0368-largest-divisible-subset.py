class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        
        
        subsets = {}
        
        nums.sort()
        for i in range(0, len(nums)):
            
            maxSubset = []
            subsets[nums[i]] = []
            for k in range(0, i):
                
                if nums[i] % nums[k] == 0 and len(maxSubset) < len(subsets[nums[k]]):   
                    maxSubset = subsets[nums[k]]

            subsets[nums[i]] = maxSubset + [nums[i]]
    
        return max(subsets.values(), key=len)
        