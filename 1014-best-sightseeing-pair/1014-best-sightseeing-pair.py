class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        
        n = len(values)
        left = [values[i] + i for i in range(n)]
        right = [values[j] - j for j in range(n)]
        
        rightMax = [0]*n
        rightMax[-1] = right[-1]
        for i in range(n-2, -1, -1):
            rightMax[i] = max(rightMax[i+1], right[i])
        
        res = 0
        for i in range(n - 1):
            res = max(res, left[i] + rightMax[i + 1])
            
        return res
            
            
            
        
        
        