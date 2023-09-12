class Solution {
public:
    int minDeletions(string s) {
        
       unordered_map<char, int>m;
       unordered_map<int, vector<char>>freqToChar;

        for(auto ch:s)
            m[ch]++;
        
        unordered_set<int>seenFreq;
        int res= 0;
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            while(m[ch] > 0 and seenFreq.find(m[ch]) != seenFreq.end())
            {
                m[ch]--;
                res++;
            }
            seenFreq.insert(m[ch]);
        }
    return res;
    }
};