class Solution {
    int getNextNumber(string text, int& i)
    {
        int res = 0, digits=0;
        while( i < text.size() and !(text[i] >= '0' and text[i] <= '9'))
            i++;
        
        while( i < text.size() and text[i] >= '0' and text[i] <= '9')
        {
            digits++;
            res= res*10 + (text[i++] - '0');
        }
    if(digits > 0)
        return res;
    return -1;
    }
public:
    bool areNumbersAscending(string s) {
        
        int i = 0, prev = -1;
        while( i < s.size())
        {
            int num = getNextNumber(s, i);
            if(num == -1)
                return true;
            
            if(num <= prev)
                return false;
            prev = num;    
            i++;
        }
    return true;
    }
};