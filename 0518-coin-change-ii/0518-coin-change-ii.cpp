class Solution {
public:
    // Recursion + Memoization
    // int solve(int amount , vector<int>& coins , int index , vector<vector<int>>& dp){
    //     if(index < 0){
    //         if(amount == 0){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(dp[index][amount] != -1){
    //         return dp[index][amount];
    //     }
    //     int notTake = solve(amount , coins , index-1 ,dp) , take = 0;
    //     if(coins[index] <= amount){
    //         take = solve(amount-coins[index] , coins , index ,dp);
    //     }
    //     return dp[index][amount] = take+notTake;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
    //     return solve(amount , coins , n-1 , dp);
    // }
    
    
    
    // Tabulation
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n+1 , vector<int>(amount+1 , 0));
    //     for(int i=0;i<n+1;i++){
    //         dp[i][0] = 1;
    //     }
    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<amount+1;j++){
    //             int notTake = dp[i-1][j] , take = 0;
    //             if(coins[i-1]<=j){
    //                 take = dp[i][j-coins[i-1]];
    //             }
    //             dp[i][j] = take+notTake;
    //         }
    //     }
    //     return dp[n][amount];
    // }
    
    
    // Tabulation + Optimization
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<int> dp(amount+1 , 0);
    //     dp[0] = 1;
    //     for(int i=1;i<n+1;i++){
    //         vector<int> temp(amount+1 , 0);
    //         temp[0] = 1;
    //         for(int j=1;j<amount+1;j++){
    //             int notTake = dp[j] , take = 0;
    //             if(coins[i-1]<=j){
    //                 take = temp[j-coins[i-1]];
    //             }
    //             temp[j] = take+notTake;
    //         }
    //         dp = temp;
    //     }
    //     return dp[amount];
    // }
    
    
    
    
    
    
    // 11/08/2023
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1 , 0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            vector<int> temp(amount+1 , 0);
            temp[0] = 1;
            for(int j = 1;j<=amount;j++){
                int notTake = dp[j];
                int take = 0;
                if(j>=coins[i-1]){
                    take = temp[j-coins[i-1]];
                }
                temp[j] = notTake+take;
            }
            dp = temp;
        }
        return dp[amount];
    }
};