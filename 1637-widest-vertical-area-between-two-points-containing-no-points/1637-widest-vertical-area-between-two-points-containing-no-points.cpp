class Solution {
    static bool comparer(const vector<int>& point1, const vector<int>&point2)
    {
        return point1[0] <= point2[0];    
    }
    
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        
        sort(points.begin(), points.end(), comparer);
        int res = 0;
        for(int i = 1; i < points.size(); i++)
            res = max(res, points[i][0] - points[i - 1][0]);
        
        return res;
    }
};