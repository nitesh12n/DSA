from collections import defaultdict

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        vis = set()
        
        adjList = defaultdict(list)
        
        for start, end in edges:
            adjList[start].append(end)
            adjList[end].append(start)
            
        
        def dfs(node, prev):
            vis.add(node)
            
            for adjNode in adjList[node]:
                if adjNode in vis:
                    if adjNode == prev:
                        continue
                    else:
                        return False
                
                if not dfs(adjNode, node):
                    return False
                
            return True    
    
        ans = dfs(0, -1)
        
        if len(vis) == n:
            return ans
        
        return False
        
    