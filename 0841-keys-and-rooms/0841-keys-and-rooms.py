class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        
        vis = set()
        
        def dfs(node):
            vis.add(node)
            
            for adjNode in rooms[node]:
                if adjNode not in vis:
                    dfs(adjNode)
                    
        dfs(0)                
    
        if len(vis) != n:
            return False
        
        return True
            