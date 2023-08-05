class Solution {
    int getHours(vector<int>& piles, int h, int k)
    {
        int hours =0;
        for(int i=0;i<piles.size(); i++)
            {
                if(piles[i] < k)
                    hours++;
                else
                {
                    hours+=piles[i]/k;
                    if(piles[i]%k > 0)
                        hours++;
                }
                if(hours > h)
                    break;
            }
    return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high =0,k; 
        int res=1;
        for(auto num : piles)
            high = max(high,num);
        
        while(low<=high)
        {
            k = low + (high-low)/2;          
            int hours = getHours(piles, h, k);               
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