class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int, int>m;
        int prefixSum;
        int totalRowSum = 0;
        int res = 0;
        
        for(int width : wall[0])
            totalRowSum+=width;
        
        for(auto row : wall)
        {
           prefixSum = 0;
           for(int i = 0; i < row.size() - 1; i++)
           {
               prefixSum+= row[i];
               m[prefixSum]++;
               res = max(res, m[prefixSum]);
           }
        }
        
        //int totalRowSum = prefixSum;
        /*for(auto it : m)
        {
            if(it.first != totalRowSum)
                res = max(res, it.second);
        }
        */
        return wall.size() - res;
    }
};