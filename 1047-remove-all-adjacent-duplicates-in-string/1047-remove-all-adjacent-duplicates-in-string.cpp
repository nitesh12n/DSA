class Solution {
public:
    string removeDuplicates(string s) {
     
        int size = s.size();
        stack<char> st;
        for(int i=0;i<size;i++)
        {
             if(!st.empty() && st.top() == s[i])
                st.pop();
             else
                 st.push(s[i]);
        }
        
        string res(st.size(), '0');
        int i = st.size() - 1;
        
        while(i >= 0)
        {
            res[i--] = st.top();
            st.pop();
        }
        return res;
    }
};