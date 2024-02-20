class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        
        n = len(nums)
        missing = 0
        for i in range(n):
            
            missing+=(i + 1)
            missing-= nums[i]
            
        return missing
            
            
        