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
    //         int change = solve(coins,amount-coins[index],index-1 ,dp);
    //         if(same != INT_MAX || change != INT_MAX){
    //             take = 1+ min(same , change);
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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(amount+1,INT_MAX));
        for(int i=0;i<n+1;i++){
            dp[i][0] = 0;
        }
        dp[0][0] = 0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                int notTake = dp[i-1][j] , take = INT_MAX;
                if(coins[i-1] <= j){
                    take = min(dp[i][j-coins[i-1]] , dp[i-1][j-coins[i-1]]);
                    if(take < INT_MAX){
                        take+=1;
                    }
                }
                dp[i][j] = min(take , notTake);
            }
        }
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<amount+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};