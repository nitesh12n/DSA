class Solution {
public:
    vector<int> getRow(int rowIndex) {
       
        vector<int>res;
        for(int i=0; i<=rowIndex; i++)
        {
            long value=1;            
            for(int j=1; j<=i;j++)
            {
               value*=rowIndex+1-j;
               value/=j;
                
            }
            res.push_back(value);
        }
        return res;
    }
};