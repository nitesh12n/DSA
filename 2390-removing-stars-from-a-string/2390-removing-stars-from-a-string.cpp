class Solution {
public:
    string removeStars(string s) {
        
        stack<char>st;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*')
                st.pop();
            else
               st.push(s[i]); 
        }
        
        string res(st.size(), '0');
        int index = st.size() - 1;
        while(!st.empty())
        {
            res[index--] = st.top();
            st.pop();
        }
    return res;
    }
};