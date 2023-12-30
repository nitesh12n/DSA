class Solution {
public:
    int maxScore(string s) {
       
        vector<int>onesSum(s.size());
        onesSum[s.size() - 1] = 0;
        
        for(int i = s.size() - 2; i>=0; i--)
            onesSum[i] = onesSum[i + 1] + (s[i + 1] == '1');
        
        int curr = 0, res = 0;
        for(int i = 0; i < s.size() - 1; i++)
        {
            curr+= s[i] == '0';
            res = max(res, curr + onesSum[i]);
        }
        return res;    
    }
};