class Solution {
    
    bool isSelfDividing(int num)
    {
        int n = num;
        while(n > 0)
        {
            int digit = n%10;
            
            if(digit == 0 or num%digit != 0)
                return false; 
            n/= 10;
        }
        return true;
    }
        
public:
    vector<int> selfDividingNumbers(int left, int right) {
     
        vector<int>res;
        for(int i = left; i<= right; i++)
            if(isSelfDividing(i))
                res.push_back(i);
        return res;
    }
};