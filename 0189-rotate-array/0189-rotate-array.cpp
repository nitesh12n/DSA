class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;
        k = n-k;
        if(k==0)
            return;
        
        vector<int>temp;
        
        for(int i=0; i<k;i++)
            temp.push_back(nums[i]);
        
        for(int i=0;i<n-k;i++)
            nums[i] = nums[i+k];
        
        int j=0;
        for(int i = n-k;i<n; i++)
            nums[i] = temp[j++];
        
        return;
    }
};