class Solution {
    
    bool isPalindrome(string str)
    {
        int low = 0; int high  = str.size()-1;
        while(low<high)
        {
            if(str[low] != str[high])
                return false;
            low++;
            high--;
        }
    return true;
    }
    
    void partition(string s, int index, vector<string>&temp, vector<vector<string>>& res)
    {
        if(index == s.size())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<s.size();i++)
        {
            string str = s.substr(index, i-index+1);
            if(isPalindrome(str))
            {
                temp.push_back(str);
                partition(s, i+1, temp, res);
                temp.pop_back();
            }
        }
        
    }
public:
    vector<vector<string>> partition(string s) {
     
        vector<string>temp;
        vector<vector<string>>res;
        
        partition(s, 0, temp, res);
        return res;
    }
};