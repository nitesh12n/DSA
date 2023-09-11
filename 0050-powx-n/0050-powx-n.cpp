class Solution {
    double evaluate(double x, long long n) {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 1/evaluate(x, (-1)*n);
        
        
        if(n%2 != 0 )
            return x*evaluate(x, n-1);
        
        return evaluate(x*x, n/2);
    }
public:
    double myPow(double x, int n) {
        return evaluate(x, n);  
    }
};