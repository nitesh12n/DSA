class Solution {
    long getCoins(long n)
    {
        return n*(n+1)/2;
    }
public:
    int arrangeCoins(int n) {
        
        int low = 0, high = n, mid, res = 0;
        
        while(low <=high)
        {
            mid = low + (high - low)/2;
            
            long coins = getCoins(mid);
            
            if(coins > n)
                high = mid - 1;
            else
            {
                low = mid + 1;
                res = mid;
            }
        }
        return res;
    }
};