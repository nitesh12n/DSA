class Solution {
    bool isValidIp(string s)
    {
        int size = s.size();
        if(size  == 1)
            return true;
        
        if(s[0] == '0' or size > 3)
            return false;
        
        return stoi(s) <= 255;
    }
    void restoreIpAddresses(string s, int index, int dots, string temp, vector<string>& res)
    {
        if(dots == 0 and index < s.size())
            return;
        if(index == s.size())
        {
            if(dots == 0)
                res.push_back(temp.substr(0, temp.size()-1));
            else
                return;
        }
        for(int i=index; i< s.size(); i++)
        {
            string str = s.substr(index, i - index + 1);
            if(isValidIp(str) and dots > 0)
                restoreIpAddresses(s, i + 1, dots - 1, temp + str + '.', res);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp;
        restoreIpAddresses(s, 0, 4, temp, res);
        return res;
    }
};