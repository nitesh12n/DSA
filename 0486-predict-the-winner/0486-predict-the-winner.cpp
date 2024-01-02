class Solution {

    bool predict(vector<int>&nums, int start, int end, bool turn, int p1score, int p2score)
    {
        if(start > end)
            return p1score >= p2score;
        
        if(turn == 0)    
        return predict(nums, start + 1, end, !turn, p1score + nums[start], p2score) 
                or predict(nums, start, end - 1, !turn, p1score + nums[end], p2score);
                
         return predict(nums, start + 1, end, !turn, p1score, p2score + nums[start]) 
                and predict(nums, start, end - 1, !turn, p1score, p2score + nums[end]);       
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return predict(nums, 0, nums.size()-1, false, 0, 0);
    }
};