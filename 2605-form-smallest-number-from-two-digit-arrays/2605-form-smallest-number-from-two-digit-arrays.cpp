class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
       
        unordered_map<int,int>m;
        int min1 = 10, min2 = 10;
        for(auto num : nums1)
        {
            m[num]++;
            min1 = min(min1, num);
        }
        sort(nums2.begin(), nums2.end());
        for(auto num : nums2)
        {
            if(m.find(num) != m.end())
                return num;
            min2 = min(min2, num);
        }
    return min1 < min2 ? min1*10 + min2 : min2*10 + min1;
        
    }
};