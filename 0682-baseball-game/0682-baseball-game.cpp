class Solution {
public:
    int calPoints(vector<string>& operations) {
                
        stack<int>s;                
        for(int i=0; i<operations.size();i++)
        {
            if(operations[i] == "C")
                s.pop();
            else if (operations[i] == "D")
            {
                int score = s.top();
                s.push(2*score);
            }
            else if (operations[i]== "+")
            {
                int score1 = s.top();
                s.pop();
                int score2 = s.top();
                s.push(score1);
                s.push(score1+score2);
            }
            else
                s.push(stoi(operations[i]));
        }
        int res = 0;
        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }
        return res;
    }
};