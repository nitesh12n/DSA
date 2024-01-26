class Solution:
    def maxNumberOfApples(self, weight: List[int]) -> int:
        
        res = 0
        
        
        weight.sort()
        currWeight = 0
        maxWeight = 5000
        for apple in weight:
            if currWeight + apple <= maxWeight:
                currWeight+= apple
                res+=1
            else:
                break
        return res