class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>> mp;
        string s= "";
        string ans="";
        for(int i=0;i<text.length();i++){
            if(text[i] == ' '){
                int l = s.length();
                mp[l].push_back(s);
                s="";
            }else{
                s+=text[i];
            }
        }
        int l = s.length();
        mp[l].push_back(s);
        int flag=0;
        for(auto it: mp){
            // sort(it.second.begin(), it.second.end());
            for(auto i: it.second){
                if(flag==0){
                    if(i[0] >= 97){
                        i[0]-='a';
                        i[0]+='A';
                    }
                    flag=1;
                    ans+=i;
                    ans+=" ";
                }else{
                    if(i[0] < 97){
                        i[0]-='A';
                        i[0]+='a';
                    }
                    ans+=i;
                    ans+=" ";
                }
            }
        }
        ans.erase(ans.length()-1);
        return ans;
    }
};