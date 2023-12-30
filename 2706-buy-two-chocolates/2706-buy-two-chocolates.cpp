class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int chocolate1 = prices[0], chocolate2 = INT_MAX;
        
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] >= chocolate1 and prices[i] < chocolate2)
                chocolate2 = prices[i];

            if(prices[i] <= chocolate1)
            {
                chocolate2 = chocolate1;
                chocolate1 = prices[i];
            }
        }
        int total = chocolate1 + chocolate2; 
        if(total <= money)
            return money - total;
        return money;
    }
};