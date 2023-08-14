class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        
        for(int num : nums)
            pq.push(num);
        
        int res;
        while(!pq.empty() and k-->0)
        {
            res = pq.top();
            pq.pop();
        }
    return res;
    }
};