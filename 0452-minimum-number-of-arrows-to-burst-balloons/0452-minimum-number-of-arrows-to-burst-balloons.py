class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        
        points.sort(key = lambda x : x[1])
        res = 1
        
        end = points[0][1]
        
        for x, y in points:
            
            if end < x:
                res+=1
                end = y
                
        return res