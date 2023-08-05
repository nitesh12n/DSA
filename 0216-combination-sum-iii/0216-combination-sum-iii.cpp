class Solution {
    void combination(int k, int n, int i, vector<int>& temp, vector<vector<int>>& res)
    {
        if(n==0 and k==0)
        {
            res.push_back(temp);
            return;
        }
        
        if(i>9 or k==0 or n < 0)
            return;
        
        //not take
        combination(k, n, i+1, temp, res);
        //take
        temp.push_back(i);
        combination(k-1, n-i, i+1, temp, res);
        temp.pop_back();
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        combination(k, n, 1, temp, res);
        return res;
        
    }
};