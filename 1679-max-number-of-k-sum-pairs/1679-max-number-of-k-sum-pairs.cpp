class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        int res = 0;
        for(int num : nums)
        {
            if(m.find(k - num) != m.end() and m[k-num] > 0)
            {
                m[k-num]--;
                
                res++;
            }
            else
                m[num]++;
        }
    return res;
    }
};