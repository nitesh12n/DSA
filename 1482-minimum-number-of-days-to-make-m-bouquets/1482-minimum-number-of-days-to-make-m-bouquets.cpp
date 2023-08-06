class Solution {
    
    bool isPossible(vector<int>& bloomDay, int m, int k, int day)
    {
        int count = 0;
        
        for(int i=0; i< bloomDay.size(); i++)
        {
            if(bloomDay[i] <= day)
            {
                count++;
                 if(count == k)
                 {
                     m--;
                     if(m ==0)
                        return true;
                     count=0;
                 }
            }
            else
                count=0;
        }
    return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int l = 1, n = bloomDay.size();
        int r=0,res=-1;
    
        
        for(auto d : bloomDay)
            r = max(d, r);
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            
            if(isPossible(bloomDay, m, k, mid))
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    return res;
    }
};