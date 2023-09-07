class Solution {
    static bool comparer(vector<int> a, vector<int>b)
    {
        //if(a[1] == b[1])
          //  return a[2] <= b[2];
        return a[1] < b[1];    
    }
    
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<vector<int>>allTrips = trips;
        
        sort(allTrips.begin(), allTrips.end(), comparer);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        int capacityLeft = capacity;
        
        for(int i = 0; i < allTrips.size(); i++)
        {
            auto trip = allTrips[i];
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            while(!pq.empty() and from >= pq.top().first)
            {
                capacity+= pq.top().second;
                pq.pop();
            }
            if(capacity >= numPassengers)
            {
                capacity-=numPassengers;
                pq.push({to, numPassengers});
            }
            else
                return false;
        }
    return true;
        
    }
};