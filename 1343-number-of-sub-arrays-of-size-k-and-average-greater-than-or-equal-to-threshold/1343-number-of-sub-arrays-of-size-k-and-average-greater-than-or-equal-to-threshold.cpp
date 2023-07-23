class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       
        int sum = threshold*k;
        int windowSum = 0;
        for(int i=0; i<k;i++)
            windowSum+=arr[i];
        
        int res=windowSum>=sum ? 1 : 0;
        
        for(int i=k; i<arr.size(); i++)
        {
            windowSum = windowSum - arr[i-k] + arr[i];
            
            if(windowSum>=sum)
                res++;
        }
        return res;
    }
};