class Solution {
public:
    int numberOfMatches(int n) {
        
        if(n <= 1)
            return 0;
        bool isEven = n%2 == 0;
        int matches = isEven ? n/2 : (n-1)/2;
        
        if(isEven)
            return matches + numberOfMatches(matches); 
        
        return matches + numberOfMatches(matches + 1);
    }
};