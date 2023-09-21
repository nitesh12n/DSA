class Solution {
public:
    long long smallestNumber(long long num) {
                
        vector<int>digits;
        bool isNegative = false;
        if(num < 0)
        {
            isNegative = true;
            num*=-1;
            
        }
        else if(num == 0)
            return 0;
        
        while(num)
        {
            digits.push_back(num%10);
            num/=10;
        }
        
        if(isNegative)
            sort(digits.begin(), digits.end(), greater<int>());
        else
            sort(digits.begin(), digits.end());
        
        long long res = 0;
        int zeroCount = 0;
        int i = 0;
    
       if(!isNegative) 
       {
            while(digits[i] == 0)
            {
                    zeroCount++;
                    i++;
            }
       }
        
        while(i < digits.size())
        {         
                res = res*10 + digits[i];
                if(zeroCount)
                {
                    res = res* pow(10, zeroCount);
                    zeroCount = 0;
                }
        i++;   
        }
        if(isNegative)
            return -1* res;
    return res;
        
    }
};