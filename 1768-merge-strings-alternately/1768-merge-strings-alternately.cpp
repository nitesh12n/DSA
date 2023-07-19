class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i=0;
        int j=0;
        int k = word1.size()+word2.size();
        string res;
        while(res.size() < k)
        {
            if(i<word1.size())
                res+=word1[i++];
            if(j<word2.size())
                res+=word2[j++];
        }
        return res;
    }
};