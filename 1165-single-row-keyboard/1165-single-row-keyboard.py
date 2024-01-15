class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        
        indexMap = {char: index for index, char in enumerate(keyboard)}
        
        res = 0
        lastIndex = 0
        for char in word: 
            res+= abs(indexMap[char] - lastIndex)
            lastIndex = indexMap[char]
            
        return res
                      
            
            
        
        
        