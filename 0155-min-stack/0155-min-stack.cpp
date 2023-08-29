class MinStack {
public:
    stack<int> st1 , minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(minStack.size() == 0 || minStack.top() >= val){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(minStack.top() == st1.top()){
            minStack.pop();
        }
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return minStack.top();
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