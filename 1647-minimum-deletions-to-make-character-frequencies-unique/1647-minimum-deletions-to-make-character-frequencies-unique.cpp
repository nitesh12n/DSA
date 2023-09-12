class Solution {
    int updateFrequency(unordered_map<int, vector<char>>& freqToChar, char ch, int startFreq)
    {       
        int ans = 0;
        while(startFreq > 0 and freqToChar.find(startFreq) != freqToChar.end())
        {
            ans++;
            startFreq--;
        }
        if(startFreq > 0)
            freqToChar[startFreq].push_back(ch);
    return ans;
        
    }
public:
    int minDeletions(string s) {
        
       unordered_map<char, int>m;
       unordered_map<int, vector<char>>freqToChar;

        for(auto ch:s)
            m[ch]++;
        
        for(auto it : m)
            freqToChar[it.second].push_back(it.first);
        int res = 0;
        for(auto  it : freqToChar)
        {
            auto values = it.second;
            auto freq = it.first;
            
            if(values.size() > 1)
            {
                for(int i = 0; i < values.size() - 1; i++)
                {
                    res+=updateFrequency(freqToChar, values[i], freq);
                }
            }
        }
    return res;
    }
};