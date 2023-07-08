class Solution {
public:
    bool possible(string s){
        int ans = 0,one=1;
        for(int i = s.size()-1 ; i>=0 ; i--){
            if(s[i] == '1'){
                ans+=(one);
            }
            one<<=1;
        }
        int start = 1;
        while(start != ans && start <= ans){
            start*=5;
        }
        return start == ans;
    }
    int solve(string s, int start, int end, vector<vector<int>> &dp){
        if(start > end){
            return 0;
        }
        int ans = 1e6;
        if(s[start] == '0'){
            return 1e6;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        string temp="";
        for(int i=start;i<=end;i++){
            temp+=s[i];
            if(possible(temp)){
                // cout<<temp<<" temp "<<endl;
                ans = min(ans , 1+solve(s , i+1 , end , dp));
            }
        }
        return dp[start][end] = ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n,-1));
        int ans = solve(s , 0 , s.size()-1 , dp);
        return  ans>= 1e6 ? -1 : ans;
    }
};