class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        map<char , int> mp, ansMp;
        for(auto it: s){
            mp[it]++;
        }
        for(auto it: s){
            if(!st.empty()){
                while(st.size() > 0 && st.top() > it && mp.find(st.top()) != mp.end() && ansMp.find(it) == ansMp.end()){
                    ansMp.erase(st.top());
                    st.pop();
                }
                if(ansMp.find(it) == ansMp.end()){
                    st.push(it);
                    ansMp[it]++;
                }
                mp[it]--;
                if(mp[it] == 0){
                    mp.erase(it);
                }
            }else{
                st.push(it);
                mp[it]--;
                if(mp[it] == 0){
                    mp.erase(it);
                }
                ansMp[it]++;
            }
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};