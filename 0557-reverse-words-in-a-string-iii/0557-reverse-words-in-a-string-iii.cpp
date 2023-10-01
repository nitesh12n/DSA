class Solution {
    void reverseWord(string& s, int& i)
    {
        if(i < s.size() and s[i] == ' ')
            i++;
        int end = i;
        int start = i;
        while(end < s.size() and s[end] != ' ')
            end++;
        end--;
        i = end+1;
        while(start < end)
        {
            swap(s[start], s[end]);
            start++,end--;
        }        
    }
    
    
public:
    string reverseWords(string s) {
        
        int i = 0;
        
        while(i < s.size())
        {
            reverseWord(s, i);
        }
    return s;
    }
};