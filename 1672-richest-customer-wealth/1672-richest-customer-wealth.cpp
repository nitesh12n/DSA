class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxWealth = 0;
        for(auto a: accounts)
        {
            int wealth=0;
            for(auto i: a)
                wealth+=i;
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};