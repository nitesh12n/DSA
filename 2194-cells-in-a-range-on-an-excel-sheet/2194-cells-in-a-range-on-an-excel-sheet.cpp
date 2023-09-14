class Solution {
public:
    vector<string> cellsInRange(string s) {
        
        int n = s.size();
        int row1 = s[1] - '0', row2 = s[n-1] - '0';
        char col1 = s[0], col2 = s[3];
        vector<string>res;
        for(char j = col1; j <= col2; j++)
        {
            for(int i = row1; i <= row2; i++)
                res.push_back(j + to_string(i));
        }
    return res;
    }
};