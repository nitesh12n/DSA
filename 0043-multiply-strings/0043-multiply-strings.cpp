class Solution {
public:
    string multiply(string num1, string num2) {
        
        string res(num1.size() + num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i = 0; i < num2.size(); i++)
        {
            for(int j = 0; j < num1.size(); j++)
            {
                int index = i + j;
                int prod = (num2[i] - '0')*(num1[j] - '0') + (res[index] - '0');                
                res[index] = prod%10 + '0';
                res[index + 1]+= prod/10; 
            }
        }
        int j = res.size() - 1;
        
        while(res.size() > 1 and res[j--] =='0')
            res.pop_back();
        
        reverse(res.begin(), res.end());
        return res;    
    }
};