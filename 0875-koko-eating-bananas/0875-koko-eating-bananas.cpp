class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high =0,k; 
        int res=1;
        for(auto num : piles)
            high = max(high,num);
        
        while(low<=high)
        {
            int hours =0;
            k = low + (high-low)/2;
            
            for(int i=0;i<piles.size(); i++)
            {
                if(piles[i] < k)
                    hours++;
                else
                {
                    hours+=piles[i]/k;
                    hours+=piles[i]%k > 0 ? 1 : 0;
                }
                if(hours > h)
                    break;
            }
                
                if(hours > h)
                    low = k+1;
            
                else if(hours <= h)
                {
                    res = k;
                    high = k-1;
                }
            
        }
    return res;
        
    }
};