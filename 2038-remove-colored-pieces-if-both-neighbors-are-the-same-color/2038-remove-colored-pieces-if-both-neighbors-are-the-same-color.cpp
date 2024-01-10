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
            
            int turns = j - i - 2;
            
            if(turns > 0 and colors[i] == 'A')
                countA+= turns;
            else if(turns > 0)
                countB+= turns;
            
            i = j;
        }
        
        return countA > countB;
    }
};