class Solution {
private:
    bool isOpen(char c)
    {
        return c == '(' || c=='{' || c=='[';
    }
    
    char getClose(char c)
    {
        if(c =='(')
            return ')';
        if(c =='[')
            return ']';
        if(c =='{')
            return '}';
        return '\0';
    }
public:
    bool isValid(string s) {
        
        stack<char> st;
        int size = s.size();
        
        int i =0;
        
        while(i<size)
        {
           if(isOpen(s[i]))
               st.push(getClose(s[i]));
           else if(st.empty() || s[i] != st.top())
               return false;
           else
               st.pop();
           i++; 
        }
        return st.empty();
    }
};