class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        stack<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                string temp = "";
                while(!st.empty()){
                    temp+=st.top();
                    st.pop();
                }
                ans+=temp;
                ans+=' ';
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};