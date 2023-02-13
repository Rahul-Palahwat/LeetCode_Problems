class Solution {
public:
    string ans="1";
    void solve(int n){
        if(n<=0){
            return;
        }
        int temp = 1;
        string local = "";
        int i=1;
        for(;i<ans.length();i++){
            if(ans[i] == ans[i-1]){
                temp++;
            }else{
                local+=to_string(temp);
                local+=ans[i-1];
                temp=1;
            }
        }
        local+=to_string(temp);
        local+=ans[i-1];
        // cout<<local<<endl;
        ans = local;
        solve(n-1);
    }
    string countAndSay(int n) {
        solve(n-1);
        return ans;
    }
};