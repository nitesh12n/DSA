class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        
        res = 0
        curr = 0
        for num in nums:
            
            if num == 1:
                curr+=1
            else:
                res = max(res, curr)
                curr = 0
               
        return max(res, curr)
                
            
            
        