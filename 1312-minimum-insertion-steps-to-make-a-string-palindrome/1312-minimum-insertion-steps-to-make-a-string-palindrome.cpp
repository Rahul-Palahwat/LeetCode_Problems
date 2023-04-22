class Solution {
public:
    
    // Recursion , bruteforce
    // int ans = INT_MAX;
    // void solve(int start , int end , string s , int cnt){
    //     if(start >= end){
    //         ans = min(ans , cnt);
    //         return;
    //     }
    //     if(s[start] == s[end]){
    //         solve(start+1 , end-1 , s , cnt);
    //     }
    //     solve(start+1 , end , s , cnt+1);
    //     solve(start , end-1 , s , cnt+1);
    //     return;
    // }
    // int minInsertions(string s) {
    //     int n = s.length();
    //     solve(0 , n-1 , s , 0);
    //     return ans;
    // }
    
    
    // Recursion + memoization
    // int solve(int start , int end , string s , vector<vector<int>>& dp){
    //     if(start >= end){
    //         return 0;
    //     }
    //     if(dp[start][end] != -1){
    //         return dp[start][end];
    //     }
    //     int ans = INT_MAX;
    //     if(s[start] == s[end]){
    //         ans = min(ans , solve(start+1 , end-1 , s,dp));
    //     }
    //     ans = min(ans , 1 + solve(start+1 , end , s,dp));
    //     ans = min(ans , 1 + solve(start , end-1 , s,dp));
    //     return dp[start][end]=ans;
    // }
    // int minInsertions(string s) {
    //     int n = s.length();
    //     vector<vector<int>> dp(n , vector<int>(n , -1));
    //     return solve(0 , n-1 , s , dp);
    // }
    
    
    
    
    // Now bottom up -> tabulation
    int minInsertions(string s) {
        int n = s.length();
        string temp = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(temp[i-1] == s[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};