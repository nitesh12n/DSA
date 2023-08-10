class Solution {
    
    bool isPossible(vector<int>& stations, int k, double maxDist)
    {
        int st=0;
        
        for(int i =1; i < stations.size(); i++)
        {
            double dist = stations[i] - stations[i-1];        
            if (dist==0)
                continue;
            if(dist > maxDist)
                 st+= dist/maxDist;
        }
    return st <= k;
    }
    
public:
    double minmaxGasDist(vector<int>& stations, int k) {
       
        double low =1, high = 0;
        
        for(int i =1; i < stations.size(); i++)
        {
            double dist = stations[i] - stations[i-1];
            if(dist > high)
                high = dist;
            if(dist < low)
                low = dist;
        }
        low/=k;
        
        
    while(high-low > 1e-6)
    {
        double mid = low + (high-low)/2;
        
        if(isPossible(stations, k, mid))
            high = mid;
        else
            low = mid;
    }
    return low;
    }
};