class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        
        dp = {} 
        def cost(i, prev):
            
            if i == len(costs):
                return 0
            if (i, prev) in dp:
                return dp[i, prev]
            
            res = float('inf')
            for color in range(0, 3):
                
                if prev == -1 or color != prev:
                    res = min(res, costs[i][color] + cost(i + 1, color))
            dp[i, prev] = res
            return res
                    
        return cost(0, -1)
                