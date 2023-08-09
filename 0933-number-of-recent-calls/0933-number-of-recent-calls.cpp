class RecentCounter {
    queue<int> requests;
public:
    RecentCounter() {
        
        requests = {};
    }
    
    int ping(int t) {
        int count = 0;

        requests.push(t);
        
        while(!requests.empty())
        {
            if(t - requests.front() > 3000)
                requests.pop();
            else
                break;
        }
        return requests.size();
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
