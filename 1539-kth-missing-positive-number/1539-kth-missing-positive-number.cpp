class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int i= 0, n = arr.size();
        
        int missingCount = arr[n-1] - (n-1) - 1; 
        
        if(missingCount < k)
            return arr[n-1] + k - missingCount;
        
        int low = 0, high = n-1, mid;
        while(low <= high)
        {
            mid = low + (high - low)/2;
        
            if(arr[mid] - mid - 1 >= k)
            {
                i = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        missingCount = arr[i] - i - 1; 
        return arr[i] - (missingCount - k  + 1);
    }
};