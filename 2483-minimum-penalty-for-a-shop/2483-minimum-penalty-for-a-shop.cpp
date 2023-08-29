class Solution {
public:
    int bestClosingTime(string customers) {
       
        int n = customers.size();
        int res = n, minPenalty = INT_MAX;
        vector<int>suffix(n, 0);
        int penaltyPrefix = 0;
        if(customers[n-1] == 'Y')
            suffix[n-1] = 1;
        
        for(int i = n-2; i>=0; i--)
            suffix[i] = suffix[i+1] + (customers[i] == 'Y' ? 1 : 0);
        
        for(int i=0; i < n; i++)
        {
            if(penaltyPrefix + suffix[i] < minPenalty)
            {
                minPenalty = penaltyPrefix + suffix[i];
                res = i;
            }
            if(customers[i] == 'N')
                penaltyPrefix++;     
        }
        if(penaltyPrefix < minPenalty)
        {
            minPenalty = penaltyPrefix ;
            res = n;
        }
    return res;
    }
};