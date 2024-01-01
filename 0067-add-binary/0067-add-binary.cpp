class Solution {
public:
    string addBinary(string a, string b) {
        
        int m = a.size(), n = b.size();
        int i = m - 1, j = n - 1;
        int carry = 0;
        string res;
        while( i >= 0  or j>= 0)
        {
            int sum = carry;
            if(i>=0)
              sum+= a[i] - '0';
            if(j >= 0)
              sum+= b[j] - '0';
            
            if(sum == 2)
                carry = 1, sum = 0;
            else if(sum == 3)
                carry = 1, sum = 1;
            else
                carry = 0;
            res.push_back(sum + '0');
            
            i--;
            j--;
        }
        if(carry)
            res.push_back('1');
        
        reverse(res.begin(), res.end());
        return res;
    }
};