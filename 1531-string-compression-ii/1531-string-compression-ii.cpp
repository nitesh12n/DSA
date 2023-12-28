class Solution {
    unordered_set<int>num = {1, 9, 99};
    int getLength(string& s, char lastChar, int lastCharCount, int index, int k, unordered_map<int, int>& dp)
    {
        if( k < 0)
            return 1e7;
        if(index == s.size())
            return 0;
        
        int key = index * 101 * 27 * 101 + (lastChar - 'a') * 101 * 101 + lastCharCount * 101 + k;
        if(dp.find(key) != dp.end())
            return dp[key];
        
        //delete
        int d = getLength(s, lastChar, lastCharCount, index + 1, k - 1, dp);
        
        
        //keep
        int keep = 0;
        
        if(lastChar == s[index])
            keep = getLength(s, lastChar, lastCharCount + 1, index + 1, k, dp) + (num.find(lastCharCount) != num.end() ? 1: 0);
        else
            keep = getLength(s, s[index], 1, index + 1, k, dp) + 1;
        
        return dp[key] = min(d, keep);
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        unordered_map<int, int> dp;
        return getLength(s, '0', 0, 0, k, dp);
    }
};