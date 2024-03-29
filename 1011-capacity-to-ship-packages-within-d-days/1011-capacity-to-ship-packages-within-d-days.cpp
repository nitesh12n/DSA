class Solution {
    bool isPossible(vector<int>& weights, int mid, int days)
    {
        int capacity = mid;
        for(auto weight : weights)
        {
            if(capacity >=weight)
                capacity-=weight;
            else
            {
                capacity = mid - weight;
                days--;
                if(days == 0)
                    return false;
            }
        }
    return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low =0 ,high =0,res, mid;
            
        for(auto num : weights)
        {
            low = max(low, num);
            high+=num;
        }
        
        while(low<=high)
        {
            mid = low +(high-low)/2;
            
            if(isPossible(weights, mid, days))
            {
                res = mid;
                high = mid -1;
            }
            else
                low = mid + 1;
        }
    return res;
    }
};