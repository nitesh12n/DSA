class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        
        unordered_map<int, int>m;
        int prefixSum;
        for(auto row : wall)
        {
           prefixSum = 0;
           for(auto width : row)
           {
               prefixSum+=width;
               m[prefixSum]++;
           }
        }
        
        int res = 0;
        int totalRowSum = prefixSum;
        for(auto it : m)
        {
            if(it.first != 0 and it.first != totalRowSum)
                res = max(res, it.second);
        }
        return wall.size() - res;
    }
};