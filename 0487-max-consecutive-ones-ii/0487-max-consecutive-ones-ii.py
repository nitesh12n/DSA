class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        
        left = 0
        right = 0
        
        res = 0
        if len(nums) == 1:
            return 1
        
        hasZero = False
        for num in nums:
            
            if num == 1:
                right+=1
            else:
                hasZero = True
                res = max(res, left + right + 1)
                left = right
                right = 0
        
        if hasZero:
            return max(res, left + right + 1)
        else:
            return len(nums)
                