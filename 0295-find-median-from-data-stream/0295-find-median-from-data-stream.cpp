class MedianFinder {
    vector<int>data;
    priority_queue<int>firstHalf;
    priority_queue<int, vector<int>, greater<int>>secondHalf;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        
        firstHalf.push(num);
        secondHalf.push(firstHalf.top());
        firstHalf.pop();
        
        if(secondHalf.size() > firstHalf.size())
        {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
    }
    
    double findMedian() {
                
        if(firstHalf.size() == secondHalf.size())
            return (firstHalf.top() + secondHalf.top())/2.0;
        
        return firstHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */