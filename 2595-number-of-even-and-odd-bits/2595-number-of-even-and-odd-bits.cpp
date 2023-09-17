class Solution {
public:
    vector<int> evenOddBit(int n) {
        
        bool even = true;
        vector<int>res = {0,0};
        while(n)
        {
            if(even)
                res[0]+= n&1;
            else
                res[1]+= n&1;
            n = n>>1;
            even = !even;
        }
    return res;
    }
};