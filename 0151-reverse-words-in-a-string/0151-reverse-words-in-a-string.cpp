class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> t;
        string temp = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                if(temp.size() > 0){
                    t.push_back(temp);
                }
                temp="";
            }else{
                temp+=s[i];
            }
        }
        if(temp.size() > 0){
                t.push_back(temp);
        }
        reverse(t.begin(),t.end());
        for(auto it: t){
            ans+=it;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};