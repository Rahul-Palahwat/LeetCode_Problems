class Solution {
public:
    
    // using two pointers 
    bool backspaceCompare(string s, string t) {
        stack<char> st1 , st2;
        for(auto it: s){
            if(st1.size() > 0 && it == '#'){
                st1.pop();
            }else if(it != '#'){
                st1.push(it);
            }
        }
        for(auto it: t){
            if(st2.size() > 0 && it == '#'){
                st2.pop();
            }else if(it != '#'){
                st2.push(it);
            }
        }
        if(st1.size() != st2.size()){
            return false;
        }
        while(st1.size() > 0){
            if(st1.top() != st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return true;
    }
};