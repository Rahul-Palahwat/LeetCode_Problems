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
    //     int take = INT_MIN , notTake = INT_MIN;
    //     if(s1[n] == s2[m]){
    //         take = 1 + solve(s1 , s2 , n-1 , m-1 , dp);
    //     }else{
    //         notTake = solve(s1 , s2 , n-1 , m , dp);
    //         notTake = max(notTake , solve(s1 , s2, n , m-1 , dp));
    //     }
    //     return dp[n][m] = max(take , notTake);
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n = text1.length() , m = text2.length();
    //     vector<vector<int>> dp(n , vector<int>(m, -1));
    //     return solve(text1 , text2 , n-1 , m-1 , dp);
    // }
    
    
    // Tabulation 
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length() , m = text2.length();
//         string ans ="";
//         vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));
//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<m+1;j++){
//                 if(text1[i-1] == text2[j-1]){
//                     dp[i][j] = 1+dp[i-1][j-1];
//                 }else{
//                     dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
//                 }
                
//             }
//         }
//         int i = n , j = m;
//         while(i>0 && j>0){
//             if(dp[i][j] > max(dp[i-1][j] , dp[i][j-1])){
//                 ans+=text1[i-1];
//                 i--;
//                 j--;
//             }else if(dp[i][j] == dp[i-1][j]){
//                 i--;
//             }else{
//                 j--;
//             }
//         }
//         return dp[n][m];
//     }
    
    
    
    
    int solve(int i , int j , string &text1 , string &text2 , vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(text1[i] == text2[j]){
            return dp[i][j] = 1+solve(i-1 , j-1 , text1 , text2 , dp);
        }else{
            return dp[i][j] = max(solve(i-1 , j , text1 , text2 , dp) , solve(i , j-1 , text1 , text2 , dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length() , m = text2.length();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(n-1 , m-1 , text1 , text2 , dp);
    }
};