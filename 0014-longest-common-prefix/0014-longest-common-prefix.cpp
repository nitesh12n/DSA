class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
                
        string res="";
        int index=0;
        string s=strs[0];
        
        while(index<s.size())
        {
            char ch = s[index];
            for(int i=1;i<strs.size();i++)
            {
                if(index >= strs[i].size() || strs[i][index] != ch)
                    return res;
            }
            res+=ch;
            index++;   
        }
        return res;
    }
};