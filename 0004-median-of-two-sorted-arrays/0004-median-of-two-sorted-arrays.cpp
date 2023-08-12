class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size(), n = nums2.size();
        
        int low = 0, high = m, count1, count2;
        int total = m + n;
        int l1,l2, r1, r2;
        while(low <= high)
        {
            count1 = low + (high-low)/2;
            count2 = (total + 1)/2 - count1;
            
            l1 = count1 > 0 ? nums1[count1-1] : INT_MIN;
            l2 = count2 > 0 ? nums2[count2-1] : INT_MIN;
            r1 = count1 < m ? nums1[count1] : INT_MAX;
            r2 = count2 < n ? nums2[count2] : INT_MAX;
            
            if(max(l1, l2) <= min(r1, r2))
            {
                if((m + n)%2 == 0)
                    return (max(l1, l2)  + min(r1, r2))/2.0;
                return max(l1, l2);
            }
            else if (l1 > r2)
                high = count1 - 1;
            else
                low = count1 + 1;      
        }
        return 0;
    }
};