class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result;
        
        for(int i = 0;i<=n;i++)
            result.push_back(countOneBits(i));
        return result;
    }
    
    int countOneBits(int n)
    {
        int result = 0;
        while(n)
        {
                result++;
            n&= n-1;
        }
        return result;
    }
};