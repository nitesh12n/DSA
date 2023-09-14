class Solution {
    string getMapKey(string s)
    {
        int shift = s[0] - 'a';
        string res;
        
        for(char ch : s)
            res+= (char)((ch - 'a') >= shift ? (ch - shift) : (ch + 26 - shift));
    return res;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
      
        unordered_map<string, vector<string>>m;        
        
        for(auto it : strings)
            m[getMapKey(it)].push_back(it);
        
        vector<vector<string>>res;
        for(auto it : m)
            res.push_back(it.second);
    return res;
    }
};