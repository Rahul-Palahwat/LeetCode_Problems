class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.size() <= 0){
            return -1;
        }
        queue<int> temp;
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        int t = q.front();
        q.pop();
        while(temp.size()> 0){
            q.push(temp.front());
            temp.pop();
        }
        return t;
        
    }
    
    int top() {
        if(q.size() <= 0){
            return -1;
        }
        queue<int> temp;
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        int t = q.front();
        q.pop();
        temp.push(t);
        while(temp.size()> 0){
            q.push(temp.front());
            temp.pop();
        }
        return t;
        
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */