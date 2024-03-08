import queue

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        
        res = 0
        curr = 0
        if k == 0:
            for num in nums:

                if num == 1:
                    curr+=1
                else:
                    res = max(res, curr)
                    curr = 0

            return max(res, curr)
    
        q = queue.Queue()
        
        res = 0
        total = 0
        curr = 0
        for num in nums:
            
            if num == 1:
                curr+=1
                total+=1
                
            else:
                
                if q.qsize() < k:
                    q.put(curr)
                    curr = 0
                
                else:
                    #res = max(res, total + q.qsize())
                    total-= q.get()
                    q.put(curr)
                    curr = 0
            res = max(res, total + q.qsize())
        
        return max(res, total + q.qsize())
                
                    
                    
                    
            
            
            
            
            