
class MinStack {
public:    
    vector<int> stack={};
    vector<int> minStack={};

    MinStack() {
        stack = {};
        minStack = {};
    }
    
    void push(int val) {
        int min = getMin();
        if(val < min)
            min = val;
        stack.push_back(val);
        minStack.push_back(min);
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        if(!stack.empty())
             return stack.back();
        return 0;
    }
    
    int getMin() {
    if(!minStack.empty())
        return minStack.back();
    return INT_MAX;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */