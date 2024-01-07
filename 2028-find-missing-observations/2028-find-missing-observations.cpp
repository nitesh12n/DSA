class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
     
        
        int m = rolls.size(), sum = 0;
        
        for(auto roll : rolls)
            sum+=roll;
        
        int missingSum = mean*(n + m) - sum;
        int minValue = missingSum/n, extra = missingSum%n;
        if(minValue > 6 or minValue < 1 or missingSum>6*n)
            return {};
        vector<int>res;

        for(int i = 0; i < n; i++)
        {
            res.push_back(minValue);
            if(extra)
                res[i]++, extra--;
            //if(res[i] > 6)
            //    return {};
            
        }
        return res;
    }
};