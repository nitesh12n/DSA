class Solution {
    bool isPossible(vector<int>& weights, int mid, int days)
    {
        int capacity = mid;
        int d=1;
        for(auto weight : weights)
        {
            if(capacity >=weight)
                capacity-=weight;
            else
            {
                capacity = mid - weight;
                days--;
                //if(d > days)
                //    return false;
            }
        }
    return days >0; //true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low =0 ,high =0,res;
            
        for(auto num : weights)
        {
            low = max(low, num);
            high+=num;
        }
        
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            
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