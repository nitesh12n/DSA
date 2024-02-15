class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        
        nums.sort()
        n = len(nums)
        prefixArr = [0]*n
        prefixArr[0] = nums[0]
        for i in range(1, n):
            prefixArr[i] = prefixArr[i - 1] + nums[i]
            
        
        for i in range(n - 1, 1, -1):
            
            longestSide = nums[i]
            remSum = prefixArr[i - 1]
            if longestSide < remSum:
                return prefixArr[i]    
        
        return -1
        #for i in nums:
            
        