class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
         
        totalSum = sum(nums)
        left = 0
        res = 0
        for i in range(len(nums) - 1):
            left+=nums[i]
            
            if left >= totalSum - left:
                res+=1
        return res
        