class Solution {
    void combination(int k, int n, int num, vector<int>& temp, vector<vector<int>>& res)
    {
        if(n==0 and k==0)
        {
            res.push_back(temp);
            return;
        }
        
        if(k==0 or n < 0)
            return;
        
        for(int i = num; i<=9; i++)
        { 
            temp.push_back(i);
            combination(k-1, n-i, i+1, temp, res);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        combination(k, n, 1, temp, res);
        return res;
        
    }
};