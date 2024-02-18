import queue
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        
        n = len(heights)
        
        q = queue.PriorityQueue()

        
        for i in range(n - 1):
            
            jump = heights[i + 1] - heights[i]
            
            if jump <= 0:
                continue
                
            q.put(jump)
            
            if q.qsize() > ladders:
                bricks-= q.get()
            if bricks < 0:
                return i
            
        return n - 1
                
            
            
            
            
        
            
            
            
            
            
            
        