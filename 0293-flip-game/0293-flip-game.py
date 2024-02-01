class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        
        
        res = []
        
        for i in range(0, len(currentState) - 1):
            
            if currentState[i] == '+' and currentState[i + 1] == '+':
                
                state = currentState[:i] + "--" + currentState[i+2:]
                res.append(state)
        return res
        