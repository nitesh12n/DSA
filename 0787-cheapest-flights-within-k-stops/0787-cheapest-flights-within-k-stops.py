import queue
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
              
        adj = [[] for _ in range(n)] 
        for flight in flights:
            adj[flight[0]].append((flight[1], flight[2]))
                
        dist = [float('inf')]*n
        q = queue.Queue()        
        q.put((0, src, 0))
        
        while not q.empty():        
            stops, city, cost = q.get()            
        
            if stops > k:
                break
            
            for nextCity, nextCost in adj[city]:
                
                if cost + nextCost < dist[nextCity]:
                    dist[nextCity] = cost + nextCost
                    q.put((stops + 1, nextCity, cost + nextCost))
        
        return dist[dst] if dist[dst] != float('inf') else -1
                
        