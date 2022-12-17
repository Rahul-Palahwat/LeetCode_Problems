class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(auto it: tokens){
            if(it != "+" && it != "-" && it != "*" && it != "/"){
                st.push(stoi(it));
            }else{
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                if(it == "+"){
                    st.push(t1+t2);
                }else if(it == "-"){
                    st.push(t2-t1);
                }else if( it == "*"){
                    st.push(t2*1LL*t1);
                }else{
                    st.push(t2/t1);
                }
            }
        }
        return st.top();
    }
};