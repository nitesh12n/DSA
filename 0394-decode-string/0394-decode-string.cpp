class Solution {
    
    int getCount(stack<char>&st)
    {
        string num;
        while(!st.empty() and isdigit(st.top()))
        {
            num+=st.top();
            st.pop();
        }
        reverse(num.begin(), num.end());
        return stoi(num); 
    }
    
    string getString(stack<char>&st)
    {
        string str;
        while(!st.empty() and st.top() != '[')
        {
            str+=st.top();
            st.pop();
        }
    return str;
    }
    
public:
    string decodeString(string s) {
        
        stack<char>st;
        
        for(auto ch : s)
        {
            if(ch == ']')
            {
                string str = getString(st);               
                st.pop();
                int count = getCount(st);                
                while(count--)
                {
                    for(int i = str.size() -1; i>=0; i--)
                        st.push(str[i]);
                }
            }
            else
                st.push(ch);
        }
        
        string res  = getString(st);
        reverse(res.begin(), res.end());
        return res;
    }
};