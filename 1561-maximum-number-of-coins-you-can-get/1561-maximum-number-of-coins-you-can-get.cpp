class Solution {
public:
    int maxCoins(vector<int>& piles) {
       
        int n = piles.size()/3;
        sort(piles.begin(), piles.end());
        
        
        int l = 0, r = piles.size() - 1;
        
        int res = 0;
        while(l < r)
        {
            if(r - 1 > l)
                res+= piles[r - 1];
            l++;
            r-=2;
        }
    return res;
    }
};