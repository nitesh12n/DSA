class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        int sum=0,res=0;
        m[0]=1;
        for(int num : nums)
        {
            sum+=num;
            res+=m[sum-k];
            m[sum]++;
        }
        return res;
    }
};