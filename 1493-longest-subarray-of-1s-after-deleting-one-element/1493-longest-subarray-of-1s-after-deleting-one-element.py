class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        
        n = len(nums)
        prev, res, curr = 0, 0, 0
        
        for i in range(n):
        
            if nums[i] == 1:
                curr+=1
            else:
                prev = curr
                curr = 0
            res = max(res, prev + curr)
                
        if curr == n:
            return n - 1
        
        return res