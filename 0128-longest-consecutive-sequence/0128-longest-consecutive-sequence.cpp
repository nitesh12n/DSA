class Solution {
    int getLength(unordered_set<int>&s, int num)
    {
        int res=0;
        while(s.find(num++) != s.end())
         res++;
    return res;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n==0)
            return 0;
        unordered_set<int>s;
        
        int res=1;
        
        for(auto num :nums)
            s.insert(num);
        
        for(auto it : s)
        {
            if(s.find(it-1) == s.end())
                res = max(res, getLength(s, it));        
        }
    return res;
    }
};