class Solution {
public:
    vector<int> getRow(int rowIndex) {
       
        vector<int>res;
        long value=1;   
        res.push_back(1);
        for(int i=1; i<=rowIndex; i++)
        {
            value=(value*(rowIndex-i+1))/i;
            res.push_back(value);
        }
        return res;
    }
};