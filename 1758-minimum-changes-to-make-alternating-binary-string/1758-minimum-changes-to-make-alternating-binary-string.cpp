class Solution {
    int getOperations(string s, char currChar)
    {
        unordered_map<char, char>nextChar = {{'0', '1'}, {'1', '0'}};
        int res = 0;
        for(char ch : s)
        {
            if(ch != currChar)
                res++;
            currChar = nextChar[currChar];
        }
        return res;
    }
    
public:
    int minOperations(string s) {
        
        return min(getOperations(s, '0'), getOperations(s, '1'));
    }
};