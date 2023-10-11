class Solution {
public:
    bool isStrobogrammatic(string num) {
        
       int l =0, r = num.size() - 1;
       unordered_map<char, char>m = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}};
        
        while(l < r)
        {
            if(m.find(num[l]) == m.end() or num[r] != m[num[l]])
                return false;
            l++,r--;
        }
        if(l == r and num[l] != '1' and num[l] != '8' and num[l] != '0')
            return false;
    return true;
    }
};