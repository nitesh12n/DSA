class Solution {
    bool isOperator(string token)
    {
      return token. size() == 1 and (token == "+" or token == "-" or token == "*" or token == "/");
    }
    int calculate(stack<int>& nums, string token)
    {
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        
        if(token == "+")
            return a + b;
        if(token == "-")
            return a - b;
        if(token == "*")
            return a*b;
        if(token == "/")
            return a/b;
        
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
     
        stack<int>nums;        
        
        for(auto token : tokens)
        {
            if(isOperator(token))
            {
                int res = calculate(nums, token);
                nums.push(res);
            }
            else
                nums.push(stoi(token));
        }
    return nums.top();
    }
};