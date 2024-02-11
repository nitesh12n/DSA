class Solution:
    def numWays(self, n: int, k: int) -> int:
        
        dp = {}    
        def ways(i):
            
            if i == n - 1:
                return k
            if i == n - 2:
                return k*k
            
            if i in dp:
                return dp[i]
            
            #dp[i] = (k - 1)* ways(i + 1) + 1*(k - 1)*ways(i + 2)  
            dp[i] = (k - 1)*(ways(i + 1) + ways(i + 2)) 
            return dp[i]
                
        return ways(0)
        
        
            
            
            
            
        