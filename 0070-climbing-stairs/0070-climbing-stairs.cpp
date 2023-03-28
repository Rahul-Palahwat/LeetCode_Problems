class Solution {
public:
    
    // Brute force Recursion
    // int solve(int n){
    //     if(n<=1){
    //         return 1;
    //     }
    //     return solve(n-1)+solve(n-2);
    // }
    // int climbStairs(int n) {
    //     return solve(n);
    // }
    
    // Now memoization
    int solve(int n, vector<int>& dp){
        if(n<=1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return solve(n , dp);
    }
};