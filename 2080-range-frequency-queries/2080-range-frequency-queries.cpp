class RangeFreqQuery {
    unordered_map<int, vector<int>>m;    
    int findLeft(vector<int>&indices, int left)
    {
        int l = 0, r = indices.size() - 1, res = -1;
        
        while(l<=r)
        {
            int mid  = l + (r - l)/2;
            
            if(indices[mid] >= left)
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    return res;
    }
    int findRight(vector<int>&indices, int right)
    {
        int l = 0, r = indices.size() - 1, res = -1;
        
        while(l<=r)
        {
            int mid  = l + (r - l)/2;
            
            if(indices[mid] <= right)
            {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    return res;
    }
public:
    RangeFreqQuery(vector<int>& arr) {
        m = {};
        for(int i = 0; i < arr.size(); i++)
            m[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
            
        int l = findLeft(m[value], left);
        
        if(l == -1)
            return 0;
        
        int r = findRight(m[value], right);
        if(r == -1)
            return 0;
        return r - l + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */