class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        vector<int>m(26, -1);
        int res = -1;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(m[s[i] - 'a'] == -1)
                m[s[i] - 'a'] = i;
            else
                res = max(res, i - m[s[i] - 'a'] - 1);
        }
        return res;
    }
};