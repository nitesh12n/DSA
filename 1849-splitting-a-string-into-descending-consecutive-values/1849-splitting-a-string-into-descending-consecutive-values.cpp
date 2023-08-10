class Solution {
    bool splitString(string s, int index, long int prev)
    {
        if(index == s.size())
            return true;
        
        for(int i = index; i < s.size(); i++)
        {
            if(i-index+1 == s.size())
                continue;
            long int num = stoul(s.substr(index, i - index + 1));
            if((prev == -1 or num == prev - 1) and splitString(s, i + 1, num))
                return true;
        }
    return false;
    }
public:
    bool splitString(string s) {
        
        return splitString(s, 0, -1);
    }
};