class Solution {
    void generate(int open, int close, string temp, vector<string>&res)
    {
        if(open+close==0)
        {
            res.push_back(temp);
            return;
        }
        
        if(open > 0)
            generate(open - 1, close, temp + '(', res);
        if(open < close)
            generate(open, close - 1, temp + ')', res);
        
    }
public:
    vector<string> generateParenthesis(int n) {
     
        vector<string>res;
        string temp;
        generate(n, n, temp, res);
        return res;
    }
};