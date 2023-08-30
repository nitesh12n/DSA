class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int stick : sticks)
            pq.push(stick);
        int res = 0;
        while(pq.size()>1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            res+= x+y;
            pq.push(x+y);
        }
        return res;
    }
};