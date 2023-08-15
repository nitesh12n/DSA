class Solution {
public:
    int countOdds(int low, int high) {
     
        int res = 0;
        res+= (high-low)/2;
        
        if(low%2 != 0 or high%2 != 0)
            res++;
        return res;
            
    }
};