class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
     
        
        int m = rolls.size();   
        int missingSum = mean*(n + m);
        for(auto roll : rolls)
            missingSum-=roll;
        
        if(missingSum < n or missingSum>6*n)
            return {};
        
        int minValue = missingSum/n, extra = missingSum%n;

        vector<int>res;
        for(int i = 0; i < n; i++)
        {
            res.push_back(minValue);
            if(extra)
                res[i]++, extra--;
            
        }
        return res;
    }
};