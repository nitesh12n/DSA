class Solution {
private:
    void combine(vector<int>&arr, int k, int i, vector<int>&temp, vector<vector<int>>&res)
    {
    
        if(k==0)
        {
            res.push_back(temp);
            return;
        }
        if(i == arr.size())
            return;
    
        //take
        temp.push_back(arr[i]);
        combine(arr, k-1, i+1, temp, res);
        temp.pop_back();
        combine(arr, k,i+1, temp, res);
    }
public:
    vector<vector<int>> combine(int n, int k) {
     
    vector<int>arr;
        
        for(int i=1;i<=n;i++)
            arr.push_back(i);
        vector<int>temp;
        vector<vector<int>>res;
        combine(arr, k, 0, temp, res);
        return res;
    }
};