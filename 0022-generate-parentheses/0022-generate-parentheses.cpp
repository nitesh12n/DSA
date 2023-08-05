class Solution {
    void generate(int n, int open, int close, string temp, vector<string>&res)
    {
        if(temp.size() == 2*n)
        {
            res.push_back(temp);
            return;
        }
        
        if(open < n)
            generate(n, open+1, close, temp + '(', res);
        if(open > close)
            generate(n, open, close + 1, temp + ')', res);
        
    }
public:
    vector<string> generateParenthesis(int n) {
     
        vector<string>res;
        string temp;
        generate(n, 0, 0, temp, res);
        return res;
    }
};