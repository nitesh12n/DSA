class Solution {
    int getProcessedNum(int n)
    {
        long res = 0;
        while(n)
        {
            int digit = n%10;
            res+= digit*digit;
            n/=10;
        }
    return res;
    }
public:
    bool isHappy(int n) {
        
        unordered_set<int>s;
        while(n > 1)
        {
            if(s.find(n) != s.end())
                return false;
            s.insert(n);
            n = getProcessedNum(n);
        }
    return n == 1;
    }
};