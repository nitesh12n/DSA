class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     
     int size = temperatures.size();
     stack<int> st;
     
     vector<int> answer(size, 0);
        
      for(int i = 0; i < size; i++)
      {          
         while(!st.empty() and temperatures[st.top()] < temperatures[i])
         {
             answer[st.top()] = i - st.top();
             st.pop();
         }
         st.push(i);
      }
      return answer;
    }
};