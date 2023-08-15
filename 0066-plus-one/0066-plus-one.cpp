class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       
        stack<int>s;
        vector<int>res;
        int carry = 1;
        int i;
        for(i = digits.size()-1; i>=0; i--)
        {
            int sum = digits[i] + carry;
            carry = 0;
            if(sum > 9)
            {
                s.push(sum%10);
                carry = 1;
            }
            else
            {
                s.push(sum);
                break;
            }
        }
        if(carry == 1)
            res.push_back(1);
        for(int j = 0; j<i; j++)
        {
            res.push_back(digits[j]);
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
        
        
    }
};