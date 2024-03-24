class Solution:
    def removeVowels(self, s: str) -> str:
        
        vowels = {'a', 'e','i', 'o', 'u'}
        res = ''
        for ch in s:
            
            if ch not in vowels:
                res+=ch
                
        return res
        