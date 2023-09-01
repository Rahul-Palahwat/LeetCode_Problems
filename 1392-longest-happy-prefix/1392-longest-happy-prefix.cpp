class Solution {
public:
    vector<int> piTable(string &s){
        int n = s.size();
        vector<int> ans(n , 0);
        int len = 0;
        for(int i=1;i<n;){
            if(s[i] == s[len]){
                len++;
                ans[i] = len;
                i++;
            }else if(len){
                len = ans[len-1];
            }else{
                i++;
            }
        }
        return ans;
    }
    string longestPrefix(string s) {
        string ans = "";
        vector<int> pos = piTable(s);
        int sz = pos[s.size()-1];
        for(int i=0;i<sz;i++){
            ans+=s[i];
        }
        return ans;
    }
};