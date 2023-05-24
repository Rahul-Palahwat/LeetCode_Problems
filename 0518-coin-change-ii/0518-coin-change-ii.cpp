class Solution {
public:
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
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        return solve(amount , coins , n-1 , dp);
    }
};