typedef pair<int,int> pqtype;
struct compare
{
 bool operator()(const pqtype a, const pqtype b)
    {
        return a.first > b.first;
    }
};
class Solution {
   
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
   
        unordered_map<int, int> m;
        
        for(auto num : nums)
            m[num]++;
        priority_queue<pqtype, vector<pqtype>, compare> pq;
        
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