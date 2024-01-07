class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        char minChar = 'z' + 1;
        
        
        for(auto letter : letters)
        {
            if(letter > target and letter - target < minChar - target)
                minChar = letter;
        }
        return minChar == ('z' + 1) ? letters[0] : minChar;
    }
};