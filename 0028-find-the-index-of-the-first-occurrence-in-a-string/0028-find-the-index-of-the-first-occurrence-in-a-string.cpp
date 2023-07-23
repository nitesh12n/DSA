class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int j = 0;
        int h = haystack.size();
        int n = needle.size();
        for(int i =0; i<h;i++)
        {
            if(haystack[i] == needle[0])
            {
                if(i+n-1 <h and haystack.substr(i, n) == needle)
                    return i;
            }         
        }
    return -1;
    }
};