class Solution {
public:
    
    
    // Recursion + Memoization
    // int solve(string s1 , string s2 , int i , int j , vector<vector<int>>& dp){
    //     if(j<0){
    //         return max(0 , i+1);
    //     }
    //     if(i<0){
    //         return max(0,j+1);
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int notTaken = 1+min(solve(s1 , s2 , i , j-1 ,dp) , solve(s1 , s2 , i-1 , j-1 , dp));
    //     notTaken = min(notTaken , 1+solve(s1 , s2 , i-1 , j , dp));
    //     int taken = INT_MAX;
    //     if(s1[i] == s2[j]){
    //         taken = solve(s1 ,s2 , i-1 , j-1 , dp);
    //     }
    //     return dp[i][j] = min(taken , notTaken);
    // }
    // int minDistance(string word1, string word2) {
    //     int n = word1.size() , m = word2.size();
    //     vector<vector<int>> dp(n , vector<int>(m , -1));
    //     return solve(word1 , word2 , n-1 , m-1,dp);
    // }
    
    
    
    
    // Tabulation
    // int minDistance(string word1, string word2) {
    //     int n = word1.size() , m = word2.size();
    //     vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
    //     for(int i=1;i<n+1;i++){
    //         dp[i][0] = i;
    //     }
    //     for(int i=1;i<m+1;i++){
    //         dp[0][i] = i;
    //     }
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(word1[i-1] == word2[j-1]){
    //                 dp[i][j] = dp[i-1][j-1];
    //             }else{
    //                 dp[i][j] = 1+min(dp[i-1][j-1] , min(dp[i][j-1] , dp[i-1][j]));
    //             }
    //             // cout<<dp[i][j]<<" ";
    //         }
    //         // cout<<endl;
    //     }
    //     return dp[n][m];
    // }
    
    
    // Tabulation + Optimization
    // int minDistance(string word1, string word2) {
    //     int n = word1.size() , m = word2.size();
    //     vector<int> dp(m+1 , 0) , cur(m+1 , 0);
    //     for(int i=0;i<=m;i++){
    //         dp[i] = i;
    //     }
    //     for(int i=1;i<=n;i++){
    //         cur[0]=i;
    //         for(int j=1;j<=m;j++){
    //             if(word1[i-1] == word2[j-1]){
    //                 cur[j] = dp[j-1];
    //             }else{
    //                 cur[j] = 1+min(dp[j-1] , min(dp[j] , cur[j-1]));
    //             }
    //             // cout<<cur[j]<<" ";
    //         }
    //         // cout<<endl;
    //         dp = cur;
    //     }
    //     return dp[m];
    // }
    
    
    // Tabulation + 1D DP
    // int minDistance(string word1, string word2) {
    //     int n = word1.size() , m = word2.size();
    //     vector<int> dp(m+1 , 0);
    //     for(int i=0;i<=m;i++){
    //         dp[i] = i;
    //     }
    //     for(int i=1;i<=n;i++){
    //         for(int j=m;j>0;j--){
    //             if(word1[i-1] == word2[j-1]){
    //                 dp[j] = dp[j-1];
    //             }else{
    //                 dp[j] = 1+min(dp[j-1] , min(dp[j] , dp[j-1]));
    //             }
    //         }
    //         dp[0]=i;
    //     }
    //     return dp[m];
    // }
    
    
    
    
    
    
    // Recursion + Optimization
    // int solve(int i, int j, string &s1 , string &s2 , vector<vector<int>> &dp){
    //     if(j<0){
    //         return i+1;
    //     }
    //     if(i<0){
    //         return j+1;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     if(s1[i] == s2[j]){
    //         return dp[i][j] = solve(i-1 , j-1 , s1 , s2 , dp);
    //     }
    //     int insert = 1+solve(i, j-1 , s1 , s2 , dp);
    //     int del = 1+solve(i-1 , j , s1 , s2 , dp);
    //     int replace = 1+solve(i-1 , j-1 , s1 , s2 , dp);
    //     return dp[i][j] = min(insert , min(del , replace));
    // }
    // int minDistance(string word1, string word2) {
    //     int n = word1.size() , m = word2.size();
    //     vector<vector<int>> dp(n , vector<int>(m , -1));
    //     return solve(n-1 , m-1 , word1 , word2 , dp);
    // }
    
    
    
    // Tabulation
    int minDistance(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        for(int i=0;i<=m;i++){
            dp[0][i] = i; 
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int insert = 1+dp[i][j-1];
                    int del = 1+dp[i-1][j];
                    int replace = 1+dp[i-1][j-1];
                    dp[i][j] = min(insert , min(del , replace));
                }
            }
        }
        return dp[n][m];
    }
};