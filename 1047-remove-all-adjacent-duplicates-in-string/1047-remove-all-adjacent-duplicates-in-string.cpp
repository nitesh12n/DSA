class Solution {
public:
    string removeDuplicates(string s) {
     
        int size = s.size();
        vector<char> stack;
        for(int i=0;i<size;i++)
        {
             if(!stack.empty() && stack.back() == s[i])
                stack.pop_back();
             else
                 stack.push_back(s[i]);
        }
        
        string result = "";
        while(!stack.empty())
        {
            result=stack.back() + result;
            stack.pop_back();
        }
        return result;
    }
};