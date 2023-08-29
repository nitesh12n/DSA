class Solution {
    struct custom {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second ;
        }
    };

public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto num : nums)
            m[num]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, custom>pq;        
        
        for(auto it : m)
            pq.push({it.first, it.second});
        
        vector<int>res;
        while(!pq.empty())
        {
            int freq = pq.top().second;
            int num = pq.top().first;
            pq.pop();
            while(freq--)
                res.push_back(num);
        }
        
        return res;
    }
};