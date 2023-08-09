class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int i= 0, n = arr.size();
        
        int missingCount = arr[n-1] - (n-1) - 1; 
        
        if(missingCount < k)
            return arr[n-1] + k - missingCount;
        
    
        while( i < n and arr[i] - i - 1 < k)
            i++;
                
        missingCount = arr[i] - i - 1; 
        return arr[i] - (missingCount - k  + 1);
    }
};