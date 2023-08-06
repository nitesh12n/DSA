class Solution {
    
    vector<string>m = { "", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void lc(string digits, int index, string temp, vector<string>& res)
    {
         if(index == digits.size())
         {
             if(temp.size() > 0)
                res.push_back(temp);
             return;
         }
        
        for(auto ch : m[digits[index] - '0'])
            lc(digits, index + 1, temp + ch, res);
        
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string>res;
        string temp;
        lc(digits, 0, temp, res);
        return res;
    }
};