class Solution {
    int mod = 1e9 + 7;
   long long evaluate(long long x, long long n) {
        if(n == 0)
            return 1;
        
        if(n%2 != 0 )
            return (x*evaluate(x, n-1))%mod;
        
        return evaluate((x*x)%mod, n/2)%mod;
    }
public:
    int countGoodNumbers(long long n) {
        
        return ((evaluate(4, n/2)%mod) * (evaluate(5, (n+1)/2)%mod))%mod;            
    }
};