typedef pair<int,int> pqtype;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
   
        unordered_map<int, int> m;
        
        for(auto num : nums)
            m[num]++;
        priority_queue<pqtype, vector<pqtype>, greater<pqtype>> pq;
        
        for(auto i : m)
        {
            pq.push(make_pair(i.second, i.first));
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> result;
        while(k--)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};