class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<int,int>m;
        unordered_map<int,int>b;
        for(auto ch : text)
            m[ch]++;
        
        string s = "balloon";
        
        for(auto ch :s)
            b[ch]++;
        
        int res=INT_MAX;
        for(auto it : b)
            res = min(res, m[it.first]/it.second);            
    return res;
}
};