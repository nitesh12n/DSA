class Solution {
private: 
    void combinationSum(vector<int>& candidates, int index, int target, vector<int>&temp, vector<vector<int>>&res)
    {
        if(target < 0)
            return;
        
         if(target==0)
         {
            res.push_back(temp);
            return;
         }
        if(index == candidates.size())
            return;
        //nottake
        // combinationSum(candidates, index + 1, target, temp, res);
        // //take
        // temp.push_back(candidates[index]);
        // combinationSum(candidates, index, target - candidates[index], temp, res);
        // temp.pop_back();
        
        for( int i = index; i < candidates.size(); i++)
        {
            if(candidates[i] <= target)
            {
                temp.push_back(candidates[i]);
                combinationSum(candidates, i, target - candidates[i], temp, res);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     
        vector<vector<int>>res;
        vector<int>temp;
        combinationSum(candidates, 0, target, temp, res);
        return res;
    }
};