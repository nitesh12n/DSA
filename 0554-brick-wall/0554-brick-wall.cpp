class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int, int>m;
        int prefixSum, res = 0;
        
        for(auto row : wall)
        {
           prefixSum = 0;
           for(int i = 0; i < row.size() - 1; i++)
           {
               prefixSum+= row[i];
               m[prefixSum]++;
               if(m[prefixSum] > res)
                res = m[prefixSum];
           }
        }
        return wall.size() - res;
    }
};