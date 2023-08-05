class Solution {
    
    void combination(vector<int>& candidates, int target, int index, vector<int>& temp, vector<vector<int>>& res)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        if(target < 0 || index == candidates.size())
            return;
                
        for(int i = index; i<candidates.size(); i++)
        {
            if( i > index and candidates[i-1] == candidates[i])
                continue;
            if(candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            combination(candidates, target - candidates[i], i+1, temp, res);
            temp.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int>temp;
    combination(candidates, target, 0, temp, res);
    return res;
    }
};