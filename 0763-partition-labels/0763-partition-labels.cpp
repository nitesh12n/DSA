class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int>m;
        for(int i = 0; i < s.size(); i++)
            m[s[i]] = i; 
        
        int i = 0;
        int j = 0;
        int start = 0;
        vector<int>res;
        while(i < s.size())
        {
            if(m[s[i]] >= j)
            {
                j = m[s[i]];
            }
            if(i == j)
            {
                res.push_back(j - start + 1);
                j++;
                start = j;
            }
            i++;
        }
        
    return res;
        
    }
};