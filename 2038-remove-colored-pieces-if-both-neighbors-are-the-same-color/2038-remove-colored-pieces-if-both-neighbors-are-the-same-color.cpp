class Solution {
public:
    bool winnerOfGame(string colors) {
        
        
        int countA = 0, countB = 0;
        
        int i = 0;
        
        if(colors.size() < 3)
            return false;
        
        while(i < colors.size())
        {
            int j = i; 
            while(j < colors.size() and colors[j] == colors[i])
                    j++;
            
            if(colors[i] == 'A' and j - i - 2 > 0)
                countA+= j - i - 2;
            else if(j - i - 2 > 0)
                countB+= j - i - 2;
            i = j;
        }
        
        return countA > countB;
    }
};