class Solution {
public:
    string decodeString(string s) {
        
        stack<char>st;
        
        for(auto ch : s)
        {
            if(ch == ']')
            {
                string str;
                while(st.top() != '[')
                {
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                string num;
                while(!st.empty() and isdigit(st.top()))
                {
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int count = stoi(num);                
                while(count--)
                {
                    for(int i = str.size() -1; i>=0; i--)
                        st.push(str[i]);
                }
            }
            else
                st.push(ch);
        }
        string res;
        while(!st.empty())
        {
            res+= st.top();
           st.pop(); 
        }
        reverse(res.begin(), res.end());
    return res;
    }
};