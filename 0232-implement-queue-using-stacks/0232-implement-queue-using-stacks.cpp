class MyQueue {
     stack<int>s;
    stack<int>buffer;
public:
    MyQueue() 
    { 
        s = stack<int>();
        buffer = stack<int>();
    }
    void fill()
    {
        while(!buffer.empty())
        {
            s.push(buffer.top());
            buffer.pop();
        }
    }
    
    void push(int x) {
        
        buffer.push(x);
    }
    
    int pop() 
    {
        if(s.empty())
            fill();
        
        int res = s.top();
        s.pop();
        return res;     
    }
    
    int peek() {
                
        if (s.empty())
            fill();
        return s.top();       
    }
    
    bool empty() {      
        return s.empty() and buffer.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */