class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        
        stack<int> st;
        
        int popIndex = 0;
        int size = pushed.size();
        
        for(int i = 0; i < size; i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[popIndex])
            {
                st.pop();
                popIndex++;
            }            
        }
        return popIndex == size;
    }
};