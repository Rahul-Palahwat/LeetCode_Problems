class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st.size() <= 0){
            return -1;
        }
        stack<int> temp;
        while(st.size() > 0){
            temp.push(st.top());
            st.pop();
        }
        int t = temp.top();
        temp.pop();
        while(temp.size()>0){
            st.push(temp.top());
            temp.pop();
        }
        return t;
    }
    
    int peek() {
        if(st.size() <= 0){
            return -1;
        }
        stack<int> temp;
        while(st.size() > 0){
            temp.push(st.top());
            st.pop();
        }
        int t = temp.top();
        while(temp.size()>0){
            st.push(temp.top());
            temp.pop();
        }
        return t;
    }
    
    bool empty() {
        return st.size() == 0;
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