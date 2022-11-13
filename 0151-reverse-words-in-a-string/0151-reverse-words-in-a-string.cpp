class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(temp.length()!=0)
                st.push(temp);
                temp="";
            }else{
                temp+=s[i];
            }
        }
        if(temp.length()!=0)
        st.push(temp);
        // cout<<st.size()<<endl;
        while(!st.empty()){
            ans+=st.top();
            if(st.size() != 1){
                ans+=" ";
            }
            st.pop();
        }
        return ans;
    }
};