class StockSpanner {
public:
    
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int next(int price) {
        int count = 1;
        while(st.size() > 0 && price >= st.top().first){
            count+=st.top().second;
            st.pop();
        }
        st.push({price , count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */