class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        
        int prev = -1, res = INT_MAX;
        for(int i = 0; i < wordsDict.size(); i++)
        {
            if(wordsDict[i] == word1 or wordsDict[i] == word2)
            {
                if(prev != -1 and wordsDict[prev] != wordsDict[i])
                    res = min(res, i - prev);
                prev = i;
            }
        }
        return res;
    }
};