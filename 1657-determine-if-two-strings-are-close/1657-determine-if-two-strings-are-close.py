class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        
        freq1, freq2 = {}, {}
        
        
        
        
        for ch in word1:
            freq1[ch] = freq1.get(ch, 0) + 1
        
        for ch in word2:
            freq2[ch] = freq2.get(ch, 0) + 1
        
        char1, char2 = [], []
        count1, count2 = [], []
        
        for ch, val in freq1.items():
            char1.append(ch)
            count1.append(val)
        
        for ch, val in freq2.items():
            char2.append(ch)
            count2.append(val)  
        
        
        char1 = sorted(char1)
        char2 = sorted(char2)
        
        if char1 != char2:
            return False
        
        count1 = sorted(count1)
        count2 = sorted(count2)
        
        if count1 != count2:
            return False
        
        return True

        
                
                
                
                
        
            
            
            
            
            
        
        
        
        