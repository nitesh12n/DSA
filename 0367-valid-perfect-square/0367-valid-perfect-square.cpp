class Solution {
public:
    bool isPerfectSquare(int num) {
      
        int low = 1, high = num/2;
        if(num==1)
            return true;
        while(low<=high)
        {
            long mid = low + (high-low)/2;
            long prod = mid*mid;
            if(prod == num)
                return true;
            else if(prod < num)
                low = mid + 1;
            else
                high = mid - 1;
        }
    return false;
    }
};