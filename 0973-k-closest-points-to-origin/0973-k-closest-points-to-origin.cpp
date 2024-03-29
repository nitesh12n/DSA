typedef pair<int, pair<int, int>> pqtype;
class Solution {
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pqtype>pq;
        for(auto point : points)
        {
            int x = point[0], y = point[1];
            int dist = x*x + y*y;
            pq.push({dist, {x, y}});  
            if(pq.size() > k)
                pq.pop();
        }
        
        while(!pq.empty())
        {
            auto point = pq.top();
            pq.pop();
            res.push_back({point.second.first, point.second.second});
        }
    return res;
    }
};