class Solution {
public:
    int mySqrt(int x) {
     
        int low = 1, high = x/2, res=1;
        
        if(x<2)
            return x;
        
        while(low<=high)
        {
            long mid = low+(high-low)/2;
            
            long prod = mid*mid;
            
            if(prod <= x)
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return res;
        
    }
};