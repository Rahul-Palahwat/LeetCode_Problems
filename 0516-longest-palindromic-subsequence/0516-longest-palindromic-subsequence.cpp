class Solution {
public:
    // Recursion + Memoization
    // int solve(string s1 , string s2 , int i , int j , vector<vector<int>>& dp){
    //     if(i<0||j<0){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     if(s1[i] == s2[j]){
    //         return dp[i][j] = 1+solve(s1,s2,i-1,j-1,dp);
    //     }else{
    //         return dp[i][j] = max(solve(s1,s2,i-1,j,dp) , solve(s1,s2,i,j-1,dp));
    //     }
    // }
    // int longestPalindromeSubseq(string s) {
    //     string s2 = s;
    //     reverse(s.begin() , s.end());
    //     int n = s.length();
    //     vector<vector<int>> dp(n, vector<int>(n , -1));
    //     return solve(s , s2 , n-1 , n-1 , dp);
    // }
    
    
    
    // Tabulation 
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s1.begin() , s1.end());
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};