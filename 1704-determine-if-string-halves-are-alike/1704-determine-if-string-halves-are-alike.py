class Solution:
    
    def isVowel(self, s):
        
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        return s in vowels
        
    def halvesAreAlike(self, s: str) -> bool:
        
        left, right = 0, 0
        for i in range(0, int(len(s)/2)):
            
            left+= self.isVowel(s[i])
            right+= self.isVowel(s[len(s)-i-1])
        return left == right
            
            
            