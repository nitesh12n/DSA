class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int n = s.size();
        unordered_map<char, int>m;
        int l = 0, r = 0, windowSize, mostFreq = 0,res=0;
        
        while(r < n)
        {
            m[s[r]]++;
            windowSize = r - l + 1;
            mostFreq  = max(mostFreq, m[s[r]]);
            
            if(windowSize - mostFreq <= k)
                res = max(res, windowSize);
            else
                m[s[l]]--,l++;
            
            r++;       
        }
    return res;
    }
};