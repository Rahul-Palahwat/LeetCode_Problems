class Solution {
public:
    // Recursion + Optimization
    // int solve(vector<int>& coins , int amount , int index , vector<vector<int>>& dp){
    //     if(amount == 0){
    //         return 0;
    //     }
    //     if(index < 0){
    //         if(amount == 0){
    //             return 0;
    //         }
    //         return INT_MAX;
    //     }
    //     if(dp[index][amount] != -1){
    //         return dp[index][amount];
    //     }
    //     int notTake = solve(coins , amount , index-1 ,dp) , take = INT_MAX;
    //     if(amount >= coins[index]){
    //         int same = solve(coins,amount-coins[index],index ,dp);
    //         if(same != INT_MAX){
    //             take = 1+ same;
    //         }
    //     }
    //     if(notTake != INT_MAX || take != INT_MAX){
    //         return dp[index][amount] = min(take , notTake);
    //     }
    //     return dp[index][amount] = INT_MAX;
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n , vector<int>(1e5,-1));
    //     int ans = solve(coins , amount , n-1 ,dp);
    //     if(ans != INT_MAX){
    //         return ans;
    //     }
    //     return -1;
    // }
    
    
    
    
    // Tabulation
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n+1 , vector<int>(amount+1,INT_MAX));
    //     for(int i=0;i<n+1;i++){
    //         dp[i][0] = 0;
    //     }
    //     dp[0][0] = 0;
    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<amount+1;j++){
    //             int notTake = dp[i-1][j] , take = INT_MAX;
    //             if(coins[i-1] <= j){
    //                 take = min(dp[i][j-coins[i-1]] , dp[i-1][j-coins[i-1]]);
    //                 if(take < INT_MAX){
    //                     take+=1;
    //                 }
    //             }
    //             dp[i][j] = min(take , notTake);
    //         }
    //     }
    //     // for(int i=0;i<n+1;i++){
    //     //     for(int j=0;j<amount+1;j++){
    //     //         cout<<dp[i][j]<<" ";
    //     //     }
    //     //     cout<<endl;
    //     // }
    //     return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    // }
    
    
    // Tabulation + optimization
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<int> dp(amount+1 , INT_MAX);
    //     dp[0] = 0;
    //     for(int i=1;i<n+1;i++){
    //         vector<int> temp(amount+1 , INT_MAX);
    //         temp[0] = 0;
    //         for(int j=1;j<amount+1;j++){
    //             int notTake = dp[j] , take = INT_MAX;
    //             if(coins[i-1] <= j){
    //                 take = min(temp[j-coins[i-1]] , dp[j-coins[i-1]]);
    //                 if(take < INT_MAX){
    //                     take+=1;
    //                 }
    //             }
    //             temp[j] = min(take , notTake);
    //         }
    //         dp = temp;
    //     }
    //     return dp[amount] == INT_MAX ? -1 : dp[amount];
    // }
    
    
    
    
    
    
    // Recursion + memoization
    int solve(int index , int amount, vector<int>& coins , vector<vector<int>> &dp){
        if(index < 0){
            if(amount == 0){
                return 0;
            }
            return 1e5;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int notTaken = solve(index-1 , amount , coins, dp);
        int taken = INT_MAX;
        if(coins[index] <= amount){
            taken = min(taken , 1+solve(index , amount-coins[index] , coins , dp));
        }
        return dp[index][amount] = min(taken , notTaken);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        int ans = solve(n-1 , amount , coins , dp);
        if(ans >= 1e5){
            return -1;
        }
        return ans;
    }
};