class Solution {
    void combine(int n, int k, int i, vector<int>& temp, vector<vector<int>>& res)
    {
        if(k==0)
        {
            res.push_back(temp);
            return;
        }
        if(i == n+1)
            return;
        
        combine(n, k, i+1, temp, res);
        temp.push_back(i);
        combine(n, k-1, i+1, temp, res);
        temp.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
       
        vector<int>temp;
        vector<vector<int>>res;
        
        combine(n, k, 1, temp, res);
        return res;
    }
};