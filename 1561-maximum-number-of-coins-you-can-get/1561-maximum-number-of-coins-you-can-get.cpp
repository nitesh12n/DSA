class Solution {
public:
    int maxCoins(vector<int>& piles) {
       
        int n = piles.size()/3;
        sort(piles.begin(), piles.end());
        
        
        int l = piles.size()/3, r = piles.size() - 2;
        
        int res = 0;
        while( l <= r)
        {
            res+= piles[r];
            r-=2;
        }
    return res;
    }
};