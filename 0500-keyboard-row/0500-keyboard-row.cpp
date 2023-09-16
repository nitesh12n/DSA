class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        
        unordered_map<char,int>m;
        string row1 = "qwertyuiop", row2 = "asdfghjkl", row3 = "zxcvbnm";
        
        for(auto ch : row1)
            m[ch] = 1;
         for(auto ch : row2)
            m[ch] = 2;
         for(auto ch : row3)
            m[ch] = 3;
        
        vector<string>res;
        for(auto word : words)
        {
            int row = m[tolower(word[0])];
            bool include = true;
            for(int i = 1; i < word.size(); i++)
            {
                if(m[tolower(word[i])] != row)
                    include = false;
            }
            if(include)
                res.push_back(word);
        }
    return res;
        
    }
};