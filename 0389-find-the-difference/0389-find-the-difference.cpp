class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char, int>m;
        
        for(auto ch : t)
            m[ch]++;
        
        for(auto ch : s)
            m[ch]--;

        for(auto it : m)
            if(it.second > 0)
                return it.first;
    return '\0';
    }
};