class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i=0;
        stack<int> st;
        for(int j=0;j<n;j++){
            st.push(pushed[j]);
            while(st.size() > 0 && st.top() == popped[i]){
                st.pop();
                i++;
            }
        }
        while(st.size() > 0 && st.top() == popped[i]){
            st.pop();
            i++;
        }
        return i==n;
    }
};