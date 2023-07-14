class Solution {
public:
    static bool compareInt(const pair<int,int>& p1,  const pair<int, int>& p2)
    {
        
        return (p1.second != p2.second) ? (p1.second < p2.second) : (p1.first < p2.first);
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int, int>>v;
        for(auto i:arr)
        {
            int num = i;
            int bit = 1;
            int x =0;
            int count=0;
            while(num)
            {
                if(num&bit)
                    count++;
                num=num>>1;
            }
            v.push_back({i, count});
            
        }
        sort(v.begin(), v.end(), compareInt);
        
        vector<int>res;
        for(auto i : v)
        {
            res.push_back(i.first);
        }
        return res;        
    }
};