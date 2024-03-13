class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        
        
        
        res = 0
        resIndex = -1
        
        startTime = 0
        for empId, endTime in logs:
            
            if res < endTime - startTime:
                res = endTime - startTime
                resIndex = empId
            elif res == endTime - startTime and empId < resIndex:
                resIndex = empId
                
            
            startTime = endTime
            
        return resIndex
            
            
            
            
            
        