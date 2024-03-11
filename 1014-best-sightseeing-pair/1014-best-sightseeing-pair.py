class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        
        n = len(values)        
        rightMax = [0]*n
        rightMax[-1] = values[-1] - (n - 1)
        for i in range(n-2, -1, -1):
            rightMax[i] = max(rightMax[i+1], values[i] - i)
        
        res = 0
        for i in range(n - 1):
            res = max(res, values[i] + i + rightMax[i + 1])
            
        return res
            
            
            
        
        
        