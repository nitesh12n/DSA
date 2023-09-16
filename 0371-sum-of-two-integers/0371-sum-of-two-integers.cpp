class Solution {
public:
    int getSum(int a, int b) {
        
        int carry;
        int res = 0;
        while(b != 0)
        {
            res = a^b;
            carry = (a&b)<<1;
            a = res;
            b = carry;
        }
    return a;
    }
};