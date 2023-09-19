class Solution {
public:
    int minimumDeletions(string s) {
        
        int res = s.size()-1;
        vector<int>leftCount(s.size(), 0), rightCount(s.size(), 0);
        for(int i = 1; i < s.size(); i++)
        {
            leftCount[i] = leftCount[i-1];
            if(s[i-1] == 'b')
                leftCount[i]++;           
        }
        for(int i = s.size() - 2; i>=0; i--)
        {
            rightCount[i] = rightCount[i+1];
            if(s[i+1] == 'a')
                rightCount[i]++;
                
        }
        
        for(int i = 0; i <s.size(); i++)
            res = min(res, leftCount[i] + rightCount[i]);

    return res;
    }
};