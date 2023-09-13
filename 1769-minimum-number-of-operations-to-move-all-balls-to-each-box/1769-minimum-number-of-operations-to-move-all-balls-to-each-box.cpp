class Solution {
public:
    vector<int> minOperations(string boxes) {
       
        int n = boxes.size();
        vector<int>answer(n, 0);
        int leftCount =  boxes[0] == '1' ? 1 : 0;
        for(int i = 1; i < n; i++)
        {
            int value = boxes[i-1] == '1' ? 1 : 0;
            answer[i] = (answer[i-1] + leftCount);
            leftCount+=(boxes[i] == '1' ? 1 : 0);
        }
         
        int right = 0;
        int rightCount = boxes[n-1] == '1' ? 1 : 0;
        for(int i = n-2; i >= 0; i--)
        {
            right+= rightCount;
            answer[i]+= right;
            rightCount+= (boxes[i] == '1' ? 1 : 0);
        }
        
        return answer;
    }
};