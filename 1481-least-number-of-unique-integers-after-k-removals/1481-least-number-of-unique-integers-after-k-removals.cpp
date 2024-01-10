class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        
        unordered_map<int,int>m;
        
        for(auto a : arr)
            m[a]++;
              
        vector<int>freq;        
        for(auto a : m)
            freq.push_back(a.second);
        
        sort(freq.begin(), freq.end());
        
        int res = m.size();
        for(auto f : freq)
        {
            if(f <= k)
            {
                k-= f;
                res--;
            }
            else
                break;
        }
        return res;
        
    }
};