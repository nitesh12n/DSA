class Solution {
    struct CustomComparer {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first;
    }
};
    
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, std::pair<int, int>>>, CustomComparer> pq;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int dist = abs(i -rCenter) + abs(j - cCenter);
                pq.push({dist, {i, j}});
            }
        }
        
        vector<vector<int>>res;
        
        while(!pq.empty())
        {
            auto ele = pq.top();
            pq.pop();
            res.push_back({ele.second.first, ele.second.second});
        }
    return res;
    }
};