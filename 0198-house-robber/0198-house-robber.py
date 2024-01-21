class Solution:
    def rob(self, nums: List[int]) -> int:
        
        n = len(nums)
        dp = {}
        def rob(index, prev):
            
            if index == n:
                return 0
            
            if (index, prev) in dp:
                return dp[index, prev]
            
            if prev != -1 and prev == index - 1: 
                dp[index, prev] = rob(index + 1, prev)
            else:
                dp[index, prev] = max(rob(index + 1, prev),  rob(index + 1, index) + nums[index])
            
            return dp[index, prev]
        
        return rob(0, -1)
    
        
        
        