class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int i=m, j=n;
        for(auto op : ops)
        {
            i = min(i, op[0]);
            j = min(j, op[1]);
        }
    return i*j;
    }
};