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
    int solve(int amount , vector<int>& coins , int index , vector<vector<int>>& dp){
        if(index < 0){
            if(amount == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int notTake = solve(amount , coins , index-1 ,dp) , take = 0;
        if(coins[index] <= amount){
            take = solve(amount-coins[index] , coins , index ,dp);
        }
        return dp[index][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , 0));
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                int notTake = dp[i-1][j] , take = 0;
                if(coins[i-1]<=j){
                    take = dp[i][j-coins[i-1]];
                }
                dp[i][j] = take+notTake;
            }
        }
        return dp[n][amount];
    }
};