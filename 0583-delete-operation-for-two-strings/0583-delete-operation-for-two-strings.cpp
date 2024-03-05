class Solution {
    vector<vector<int>> dp;
    int lcs(string word1, string word2, int p1, int p2) {
        
        if(p1<0 && p2<0)
            return 0;
        
        if(p1<0){
            return p2+1;
        }
        if(p2<0){
            return p1+1;
        }
        if(dp[p1][p2]!=0)
            return dp[p1][p2];
        
        char ch1 = word1[p1];
        char ch2 = word2[p2];
        if(ch1==ch2){
            dp[p1][p2] = lcs(word1, word2, p1-1, p2-1);
            return dp[p1][p2];
        }
        else {
            int insert = lcs(word1, word2, p1, p2-1);
            int del = lcs(word1, word2, p1-1, p2);
            dp[p1][p2] = 1 + min(insert, del);
            return dp[p1][p2];
        }
    }
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        dp.resize(len1 + 1, std::vector<int>(len2 + 1, 0));
        return lcs(word1, word2, len1-1, len2-1);
    }
};