class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size()%groupSize)
            return false;
        
        map<int, int>m;
        for(auto it : hand)
            m[it]++;
        int i = 0, groupCount = hand.size()/groupSize;
        while(i++ < groupCount)
        {
            int size = groupSize;
            int prev = -1;
            for(auto it : m)
            {
                if(it.second == 0)
                    return false;
                if(prev == -1 or prev == it.first - 1)
                {
                    size--;
                    if(it.second - 1 == 0)
                        m.erase(it.first);
                    else
                        m[it.first] = it.second - 1;
                    prev = it.first;
                }
                else
                    return false;
                if(size == 0)
                    break;
            }
        }
    return m.size() == 0;
    }
};