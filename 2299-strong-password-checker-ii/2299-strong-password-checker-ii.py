class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        
        charCount = 0
        upper, lower, digit, special = 0, 0, 0, 0
        
        lastChar = None
        specialChars = '!@#$%^&*()-+'
        for ch in password:
            
            if ch == lastChar:
                return False
            
            if ch.isalpha():
                
                if ch == lastChar:
                    return False
                
                elif ch.islower():
                    lower+=1
                else:
                    upper+=1
            elif ch.isnumeric():
                digit+=1
                
            elif ch in specialChars:
                special+=1
            else:
                return False
            charCount+=1
            lastChar = ch
        
        return charCount >= 8 and lower >= 1 and upper >=1 and digit >=1 and special >= 1
            
            
            
            
        
        