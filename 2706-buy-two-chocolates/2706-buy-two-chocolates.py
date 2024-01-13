class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        
        
        choc1, choc2 = 101, 102
        
        for price in prices:
            
            if price < choc1:
                choc2 = choc1
                choc1 = price
            elif price < choc2:
                choc2 = price
        total = choc1 + choc2
        
        return money - total if total <= money else money
                
                
        
        