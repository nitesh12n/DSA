#define PII pair<int, int>
class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
};
class Solution {
    
    int getCount(vector<int>& arr)
    {
        int l = 0,r = arr.size() - 1, mid, res = -1;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(arr[mid] == 1)
            {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }        
        return res + 1;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
     
        priority_queue<PII, vector<PII>, Compare> pq;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        {
            int count = getCount(mat[i]); 
            pq.push({count, i});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int>res(k);
        
        while(!pq.empty())
        {
            res[--k] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};