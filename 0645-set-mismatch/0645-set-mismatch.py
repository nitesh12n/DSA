class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        
        missing, repeated = 0, 0
        for num in nums:
            
            if nums[abs(num) - 1] < 0:
                repeated = abs(num)
            else:
                nums[abs(num) - 1] = -1 *nums[abs(num) - 1]
                
        for i in range(0, len(nums)):
            if nums[i] > 0:
                missing = i + 1 
                
        return [repeated, missing]
            
        