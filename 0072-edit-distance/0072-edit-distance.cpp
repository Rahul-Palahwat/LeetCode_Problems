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
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        for(int i=1;i<n+1;i++){
            dp[i][0] = i;
        }
        for(int i=1;i<m+1;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min(dp[i-1][j-1] , min(dp[i][j-1] , dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }
    
    
    // Tabulation + Optimization
    // int minDistance(string word1, string word2) {
    //     int n = word1.size() , m = word2.size();
    //     vector<int> dp(m+1 , 0) , cur(m+1 , 0);
    //     for(int i=1;i<=m;i++){
    //         dp[i] = i;
    //     }
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             int notTaken = 1+min(dp[j-1] , min(cur[j-1] , dp[j]));
    //             int taken = INT_MAX;
    //             if(word1[i-1] == word2[j-1]){
    //                 taken = dp[j-1];
    //             }
    //             cur[j] = min(taken , notTaken);
    //         }
    //         dp = cur;
    //     }
    //     return dp[m];
    // }
};