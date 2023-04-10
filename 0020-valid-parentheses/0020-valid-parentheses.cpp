class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it: s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }else{
                if(st.size() > 0)
                if(it == ')'){
                    if(st.top() == '('){
                        st.pop();
                    }
                    else
                    return false;
                }else if(it == '}'){
                    if(st.top() == '{'){
                        st.pop();
                    }
                    else
                    return false;
                }
                else{
                    if(st.top() == '['){
                        st.pop();
                    }else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};