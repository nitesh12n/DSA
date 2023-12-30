class Solution {
    
    bool canReach(vector<int>& arr, int i, vector<bool>&vis)
    {
        
        if(arr[i] == 0)
            return true;
        
        vis[i] = true;
        if(i + arr[i] < arr.size() and !vis[i + arr[i]] and canReach(arr, i + arr[i], vis))
            return true;
        
        if(i - arr[i] >=0 and !vis[i - arr[i]] and canReach(arr, i -  arr[i], vis))
            return true;
        
        vis[i] = false;
        return false;
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        
        vector<bool>vis(arr.size(), false);
        return canReach(arr, start, vis);
    }
};