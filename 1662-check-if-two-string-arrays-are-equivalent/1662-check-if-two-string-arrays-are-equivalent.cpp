class Solution {
    
    char getNextCharFromWord2(vector<string>& word2, int& i, int& j)
    {
        
        if(i == word2.size())
            return '\0';
        
        int res = word2[i][j];
        if(j + 1 == word2[i].size())
            i++, j = 0;
        else
            j++;
         
        return res;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int i = 0, j = 0;
        for(auto word : word1)
        {
            for(auto ch : word)
            {
                if(ch != getNextCharFromWord2(word2, i, j))
                    return false;
            }
        }
        return i == word2.size() and j == 0;
    }
};