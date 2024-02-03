class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        
        dp = {}
        def maxSum(i):
            
            if i == len(arr):
                return 0
            if i in dp:
                return dp[i]
            
            res = 0
            maxVal = 0
            for j in range(i, min(len(arr), i + k)):  
                maxVal = max(maxVal, arr[j])
                res = max(res, maxVal *(j - i + 1) + maxSum(j + 1))
                
            dp[i] = res
            return res
        
        return maxSum(0)
                
        