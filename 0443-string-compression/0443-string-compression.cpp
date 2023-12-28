class Solution {
    void pushDigits(vector<char>& chars, int number, int& index)
    {
        if(number == 1)
            return;
        
        for(auto c : to_string(number))
                chars[index++] = c;
    }
    
public:
    int compress(vector<char>& chars) {
      
        int i = 0, j = 0;
        int index = 0;
        while( i < chars.size() and j < chars.size())
        {
            int charCount = 0;
            while( j < chars.size() and chars[i] == chars[j])
            {
                charCount++;
                j++;
            }
            chars[index++] = chars[i];
            pushDigits(chars, charCount, index);
            i = j;
        }
        return index;
    }
};