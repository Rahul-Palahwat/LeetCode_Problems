class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";
        int flag=0;
        for(int i=0;i<s[0].length();i++){
            for(int j=0;j<s.size();j++){
                if(s[j].length() > i){
                    if(s[j][i] != s[0][i]){
                        flag=1;
                        break;
                    }
                }else{
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
            ans+=s[0][i];
        }
        return ans;
    }
};