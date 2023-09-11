class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       
        
        priority_queue<pair<int, char>>pq;
        
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
                
        string res;
        
        while(!pq.empty())
        {
            auto ch1 = pq.top();
            pq.pop();
            if(res.empty() or res.back() != ch1.second)
            {
                int size = min(ch1.first, 2);
                string s(size, ch1.second);
                res+= s;
                ch1.first-= size;
            }
            else
            {
                if(!pq.empty())
                {
                    auto ch2 = pq.top();
                    pq.pop();
                    res+= ch2.second;
                    ch2.first--;
                    if(ch2.first > 0)
                        pq.push(ch2);
                }
                else
                    return res;
            }          
            if(ch1.first > 0)
                pq.push(ch1);
        }
        
        return res;
    }
};