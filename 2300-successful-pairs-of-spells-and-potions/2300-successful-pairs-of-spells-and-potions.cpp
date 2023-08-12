class Solution {
    int getSuccessCount(int spell, vector<int>& potions, long long success)
    {
        int m = potions.size();
        
        int low = 0, high = m-1, res=m, mid;
        
        while(low <= high)
        {
            mid = low + (high - low)/2;
            
            if((long long)spell*(long long)potions[mid] >= success)
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;       
        }
        return m - res;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        
        int n = spells.size(), m = potions.size();
        vector<int>res;
        sort(potions.begin(), potions.end());
        for(int i=0; i<n; i++)
            res.push_back(getSuccessCount(spells[i], potions, success));
    return res;  
    }
};