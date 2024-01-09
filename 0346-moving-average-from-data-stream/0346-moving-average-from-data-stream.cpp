class MovingAverage {
    queue<int> q;
    int runningSum, windowSize;
public:
    MovingAverage(int size) {
        q = queue<int>(); 
        runningSum = 0;
        windowSize = size;
    }
    
    double next(int val) {
        
        
        q.push(val);
        runningSum+= val;
        if(q.size() > windowSize)
        {
            runningSum-= q.front();
            q.pop();
        }
        return runningSum/(double)(q.size());
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */