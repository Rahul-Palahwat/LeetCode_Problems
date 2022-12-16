class MyQueue {
public:
    stack<int> ip,op;
    MyQueue() {
        stack<int> ip,op; 
    }
    
    void push(int x) {
        while(!op.empty()){
            ip.push(op.top());
            op.pop();
        }
        op.push(x);
        while(!ip.empty()){
            op.push(ip.top());
            ip.pop();
        }
    }
    
    int pop() {
        int x = op.top();
        op.pop();
        return x;
    }
    
    int peek() {
        return op.top();
    }
    
    bool empty() {
        return op.empty();
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