class Solution {
    
    bool isGoodString(string word, unordered_map<char,int>charMap)
    {
        for(auto ch : word)
        {
            if(charMap.find(ch) == charMap.end() or charMap[ch] == 0)
                return false;
            charMap[ch]--;
        }
    return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int>charMap;
        int res = 0;      

        for(auto ch : chars)
            charMap[ch]++;        
        
        for(auto word : words)
            if(isGoodString(word, charMap))
                res+= word.size();
        
        return res;   
    }
};