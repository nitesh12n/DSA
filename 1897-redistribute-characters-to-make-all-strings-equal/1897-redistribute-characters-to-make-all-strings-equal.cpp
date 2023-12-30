class Solution {
public:
    bool makeEqual(vector<string>& words) {
       
        vector<int>frequencies(26, 0);
        int wordsCount = words.size();
        
        for(auto word : words)
            for(auto letter : word)
                frequencies[letter - 'a']++;
        
        for(auto freq : frequencies)
            if(freq%wordsCount != 0)
                return false;
        
        return true;
        
    }
};