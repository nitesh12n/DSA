from queue import PriorityQueue
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        
        pq = PriorityQueue()
              
        for stick in sticks:
            pq.put(stick)   
        res = 0
        while(pq.qsize()> 1):
            
            stick1 = pq.get()
            stick2 = pq.get()
            res+= stick1+stick2
            pq.put(stick1 + stick2)
            
        return res
            
            
        