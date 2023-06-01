class Solution {
public:
    // Recursion + Memoization
    // int solve(string s1 , string s2 , int i , int j , vector<vector<int>>& dp){
    //     if(i<0 || j<0){
    //         if(j < 0){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int notTaken = solve(s1 , s2 , i-1 , j , dp) , taken = 0;
    //     if(s1[i] == s2[j]){
    //         taken = solve(s1 , s2 , i-1 , j-1 , dp);
    //     }
    //     return dp[i][j] = notTaken+taken;
    // }
    // int numDistinct(string s, string t) {
    //     int n = s.length() , m = t.length();
    //     vector<vector<int>> dp(n, vector<int>(m , -1));
    //     return solve(s, t , n-1 , m-1 , dp);
    // }
    
    
    // Tabulation
    // int numDistinct(string s, string t) {
    //     int n = s.size() , m = t.size();
    //     vector<vector<double>> dp(n+1 , vector<double>(m+1 , 0));
    //     for(int i=0;i<n+1;i++){
    //         dp[i][0] = 1;
    //     }
    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<m+1;j++){
    //             if(s[i-1] == t[j-1]){
    //                 dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
    //             }else{
    //                 dp[i][j] = dp[i-1][j];
    //             }
    //         }
    //     }
    //     return (int)dp[n][m];
    // }
    
    
    // Tabulation + Optimization 2 Arrays
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<double> dp(m+1 , 0);
        vector<double> cur(m+1 , 0);
        dp[0]=1;
        cur[0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = dp[j-1]+dp[j];
                }else{
                    cur[j] = dp[j];
                }
            }
            dp = cur;
        }
        return (int)dp[m];
    }
    
};