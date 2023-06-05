class Solution {
public:
    
    // Recursion + Memoization
    // int solve(int index , bool buy, vector<int>& prices , vector<vector<int>>& dp){
    //     if(index >= prices.size()){
    //         return 0;
    //     }
    //     int profit = 0;
    //     if(dp[index][buy] != -1){
    //         return dp[index][buy];
    //     }
    //     if(buy){
    //         int taken = -prices[index] + solve(index+1 , false , prices , dp);
    //         int notTaken = solve(index+1 , buy , prices , dp);
    //         profit = max(taken , notTaken);
    //     }else{
    //         int taken = prices[index]+solve(index+2 , true , prices , dp);
    //         int notTaken = solve(index+1 , false , prices , dp);
    //         profit = max(taken , notTaken);
    //     }
    //     return dp[index][buy] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n , vector<int>(2,-1));
    //     return solve(0 , true , prices , dp);
    // }
    
    
    
    // Tabulation
    int solve(int index , bool buy, vector<int>& prices , vector<vector<int>>& dp){
        if(index >= prices.size()){
            return 0;
        }
        int profit = 0;
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        if(buy){
            int taken = -prices[index] + solve(index+1 , false , prices , dp);
            int notTaken = solve(index+1 , buy , prices , dp);
            profit = max(taken , notTaken);
        }else{
            int taken = prices[index]+solve(index+2 , true , prices , dp);
            int notTaken = solve(index+1 , false , prices , dp);
            profit = max(taken , notTaken);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2 , vector<int>(2,0));
        for(int index = n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit = 0;
                if(buy){
                    int taken = -prices[index] + dp[index+1][false];
                    int notTaken = dp[index+1][buy];
                    profit = max(taken , notTaken);
                }else{
                    int taken = prices[index]+dp[index+2][true];
                    int notTaken = dp[index+1][false];
                    profit = max(taken , notTaken);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][true];
    }
};