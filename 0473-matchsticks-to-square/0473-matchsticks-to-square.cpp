class Solution {
    bool makesquare(vector<int>& matchsticks, int k, int currSum, int sum, string& taken, unordered_map<string, bool>& m)
    {
        
        if(currSum == sum)
        {
            k--;
            if(k==0)
            {
                return true;
                for(auto t : taken)
                {
                    if( t == false)
                        return false;
                }
            }
            currSum=0;
        }
        
        if(m.find(taken) != m.end())
            return m[taken];
        
        bool res = false;
        for(int i=0; i < matchsticks.size(); i++)
        {
            if(taken[i] == '0' and currSum + matchsticks[i] <= sum)
            {
                taken[i] = '1';
                res = makesquare(matchsticks, k, currSum + matchsticks[i], sum, taken, m);
                taken[i] = '0';
                if(res)
                    return m[taken] = res;
            }
        }
    return m[taken] = res;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        string taken(matchsticks.size(), '0');
        unordered_map<string, bool> m;
        int sum = 0;
        for(auto m : matchsticks)
            sum+=m;
        
        if(sum%4 != 0)
            return false;
        return makesquare(matchsticks, 4, 0, sum/4, taken, m);
    }
};