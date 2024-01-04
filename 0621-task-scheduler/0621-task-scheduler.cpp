class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int>freq; 
        
        for(auto task : tasks)
            freq[task]++;
        
        priority_queue<int>pq;
        
        
        for(auto it : freq)
            pq.push(it.second);
        
        int res = 0;
        while(!pq.empty())
        {
            vector<int>stagingQueue;
            int cycle = n + 1;
            
            while(cycle and !pq.empty())
            {
                int count = pq.top();
                pq.pop();
                
                if(count > 1)
                    stagingQueue.push_back(count - 1);
                
                cycle--;
                res++;
                
            }
            
            for(auto it : stagingQueue)
                pq.push(it);
            
            if(pq.empty())
                break;
            else
                res+= cycle;
            
        }
        
        return res;
        
    }
};