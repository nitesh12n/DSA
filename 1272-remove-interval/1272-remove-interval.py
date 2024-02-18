class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        
        res = []
        for interval in intervals:
            
            start, end = interval
            if end < toBeRemoved[0] or start > toBeRemoved[1]:
                res.append(interval)
        
            else:    
                if start < toBeRemoved[0]:
                    res.append([start, toBeRemoved[0]])
                if end > toBeRemoved[1]:
                    res.append([toBeRemoved[1], end])
        return res
                
        