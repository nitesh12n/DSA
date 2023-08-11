class Solution {
    int getFirstPosIndex(vector<int>& nums, int n)
    {
        int low = 0, high = n-1, mid, index=n;
        
        while(low <= high)
        {
            mid = low + (high - low)/2;
            
            if(nums[mid] < 0)
                low = mid + 1;
            else if (nums[mid] >=0)
            {
                high = mid - 1;
                index = mid;
            }
        }
    return index;
    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();    
    int right = getFirstPosIndex(nums, n);      
    int left = right - 1;
    
    vector<int>res;
    while(left>= 0 and right <n)
    {
        if(abs(nums[left]) <= nums[right])
        {
            res.push_back(nums[left]*nums[left]);
            left--;
        }
        else
        {
            res.push_back(nums[right]*nums[right]);
            right++;
        }
    }
    while(left>=0)
    {
        res.push_back(nums[left]*nums[left]);
        left--;
    }
    while(right <n)
    {
        res.push_back(nums[right]*nums[right]);
        right++;
    } 
    return res;
    }
};