class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        
        
        allwins = set()
        lostMatches = {}
        
        for match in matches:
            
            winner = match[0]
            loser = match[1]
            
            lostMatches[loser] = lostMatches.get(loser, 0)  + 1
            allwins.add(winner)
            
        oneLoss = []    
        for player, lostCount in lostMatches.items():
            
            if lostCount == 1:
                oneLoss.append(player)
            allwins.discard(player)
        
        
        return [sorted(allwins), sorted(oneLoss)]
                
            
        
        