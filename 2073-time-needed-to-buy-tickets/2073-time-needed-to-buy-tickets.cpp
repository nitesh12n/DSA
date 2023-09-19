class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
       list<pair<int,int>>l;
        
        for(int i = 0; i < tickets.size(); i++)
            l.push_back({tickets[i], i});
        
        int time = 0;
        while(!l.empty())
        {
            auto p = l.front();
            time++;
            if(p.first == 1 and p.second==k)
                return time;
            l.pop_front();
            if(p.first - 1 > 0)
                l.push_back({p.first-1, p.second});
        }
        
    return -1;
    }

};