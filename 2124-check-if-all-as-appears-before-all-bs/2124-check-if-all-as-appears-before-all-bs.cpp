class Solution {
public:
    bool checkString(string s) {
        
        bool hasB = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(hasB and s[i] == 'a')
                return false;
            
            if(s[i] == 'b')
                hasB = true;
        }
     return true;   
    }
};