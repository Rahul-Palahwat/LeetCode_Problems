class Solution {
public:
    // Recursion + Optimization
    // int solve(string s1 , string s2 , int n , int m , vector<vector<int>>& dp){
    //     if(n<0 || m<0){
    //         return 0;
    //     }
    //     if(dp[n][m] != -1){
    //         return dp[n][m];
    //     }
    //     int notTake1 = solve(s1 , s2 , n-1 , m , dp);
    //     int notTake2 = solve(s1 , s2, n , m-1 , dp);
    //     int take = INT_MIN;
    //     if(s1[n] == s2[m]){
    //         take = 1 + solve(s1 , s2 , n-1 , m-1 , dp);
    //     }
    //     return dp[n][m] = max(take , max(notTake1 , notTake2));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.length() , m = text2.length();
    //     vector<vector<int>> dp(n , vector<int>(m, -1));
    //     return solve(text1 , text2 , n-1 , m-1 , dp);
    // }
    
    
    // Tabulation 
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length() , m = text2.length();
        vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                int notTake1 = dp[i-1][j] , take = INT_MIN , notTake2 = dp[i][j-1];
                if(text1[i-1] == text2[j-1]){
                    take = 1+dp[i-1][j-1];
                }
                dp[i][j] = max(take , max(notTake1 , notTake2));
            }
        }
        return dp[n][m];
    }
};