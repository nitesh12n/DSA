class Solution {
public:
    string reorganizeString(string s) {
     
        unordered_map<char, int>m;
        
        for(auto ch : s)
            m[ch]++;
        
        priority_queue<pair<int, char>>pq;
        
        for(auto it : m)
            pq.push({it.second, it.first});
                
        string res;
        
        while(!pq.empty())
        {
            auto ch1 = pq.top();
            pq.pop();
            if(res.empty() or res.back() != ch1.second)
            {
                res+= ch1.second;
                ch1.first--;
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
                    return "";
            }
            if(ch1.first > 0)
                pq.push(ch1);
        }
        
        return res;
    }
};