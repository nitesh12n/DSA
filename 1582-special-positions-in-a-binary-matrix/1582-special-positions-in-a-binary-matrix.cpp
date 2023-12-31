class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        vector<int>row(m, 0), col(n, 0);
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1)
                    row[i]++,col[j]++;
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j]*row[i]*col[j] == 1)
                    res++;
            }
        }
        return res;
        
    }
};