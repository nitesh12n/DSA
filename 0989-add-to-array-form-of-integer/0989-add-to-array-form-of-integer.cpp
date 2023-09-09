class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int carry = 0, i = num.size(), operand1, operand2;
        vector<int>res;
        while(--i >=0 or k)
        {    
            operand1 = i >=0 ? num[i] : 0;
            operand2 = k%10;
            k/=10;
            int result = operand1 + operand2 + carry;            
            res.push_back(result%10);
            carry = result/10;     
        }
        if(carry)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};