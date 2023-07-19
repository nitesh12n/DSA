class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i=s.size()-1;
        
        while(s[i]== ' ' and i>=0)
            i--;
        int length=0;
        while(i>=0 and s[i]!= ' ')
        {
            length++;
            i--;
        }
        return length;
    }
};