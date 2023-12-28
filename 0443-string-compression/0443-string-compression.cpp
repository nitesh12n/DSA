class Solution {
    void pushDigits(vector<char>& res, int number)
    {
        if(number == 1)
            return;
        
        vector<int>digits;
        while(number > 0)
        {
            digits.push_back(number%10);
            number/=10;
        }
        
        for(int i = digits.size() - 1; i>=0; i--)
            res.push_back('0' + digits[i]);
    }
    
public:
    int compress(vector<char>& chars) {
      
        int i = 0, j = 0;
        vector<char>res;
        while( i < chars.size() and j < chars.size())
        {
            int charCount = 0;
            while( j < chars.size() and chars[i] == chars[j])
            {
                charCount++;
                j++;
            }
            res.push_back(chars[i]);
            pushDigits(res, charCount);
            i = j;
        }
        chars = res;
        return chars.size();
    }
};