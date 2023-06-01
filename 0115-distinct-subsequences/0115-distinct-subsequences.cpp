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
    long long MOD = 1e9+7;
    int numDistinct(string s, string t) {
        int n = s.length() , m = t.length();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1 , 0));
        for(int i=0;i<n+1;i++){
            dp[0][i] = 1;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[j-1] == t[i-1]){
                    if(dp[i][j-1] == 0){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])%MOD;
                    }
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        // for(int i=1;i<m+1;i++){
        //     for(int j=1;j<n+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[m][n];
    }
    
};