class Solution {
    unordered_set<char>vowels = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char ch)
    {
        return vowels.find(tolower(ch)) != vowels.end();
    }
public:
    string reverseVowels(string s) {
        
        int low = 0, high = s.size() - 1; 
        while(low < high)
        {
            while(low < high and !isVowel(s[low]))
                low++;
            while(low < high and !isVowel(s[high]))
                high--;
            
            if(low < high)
                swap(s[low], s[high]);
            low++;
            high--;
        }
        return s;
    }
};