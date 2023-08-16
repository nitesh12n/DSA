class Solution {
    pair<int, int> getMax(vector<int>& nums, int k)
    {
        int count=0,maxValue = INT_MIN;
        for(int i=0; i<k;i++)
        {
            if(nums[i] > maxValue)
            {
                count=1;
                maxValue = nums[i];
            }
            else if(nums[i] == maxValue)
                count++;
        }
        return {maxValue, count};
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
        priority_queue<pair<int, int>>pq;
        
        for(int i=0; i<k-1;i++)
            pq.push({nums[i], i});
        vector<int>res;          
        for(int i = k-1; i< nums.size(); i++)
        {
            pq.push({nums[i], i});
            while(!pq.empty() and pq.top().second < i-k+1)
                pq.pop();
            
            res.push_back(pq.top().first);
        }
        return res;        
    }
};