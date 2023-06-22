class Solution {
public:
    // int solve(int index , bool buy , vector<int>& prices , int fee , vector<vector<int>> &dp){
    //     if(index == prices.size()){
    //         return 0;
    //     }
    //     if(dp[index][buy] != -1){
    //         return dp[index][buy];
    //     }
    //     if(buy){
    //         return dp[index][buy] = max(-prices[index] + solve(index+1 , false , prices , fee,dp) , solve(index+1 , buy , prices , fee ,dp));
    //     }
    //     return dp[index][buy] = max(prices[index]-fee+solve(index+1 , true , prices , fee , dp) , solve(index+1 , buy , prices , fee , dp));
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n , vector<int>(2 , -1));
    //     return solve(0 , true , prices , fee , dp);
    // }
    
    
    
    // Tabulation
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2 , 0));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[index][buy] = max(-prices[index] + dp[index+1][false] , dp[index+1][buy]);
                }else{
                    dp[index][buy] = max(prices[index]-fee+dp[index+1][true], dp[index+1][buy]);
                }
            }
        }
        return dp[0][true];
    }
};




// Recursion + Memoization
    // int solve(int index , bool buy , vector<int>& prices , int fee , vector<vector<int>>& dp){
    //     if(index == prices.size()){
    //         return 0;
    //     }
    //     if(dp[index][buy] != -1){
    //         return dp[index][buy];
    //     }
    //     if(buy){
    //         return dp[index][buy] = max(-prices[index]+solve(index+1,false,prices,fee , dp),solve(index+1,buy,prices,fee ,dp));
    //     }
    //     return dp[index][buy] = max(prices[index]-fee+solve(index+1,true,prices,fee , dp) , solve(index+1,buy,prices,fee , dp));
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n , vector<int>(2,-1));
    //     return solve(0 , true , prices , fee , dp);
    // }
    
    
    // Tabulation
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1 , vector<int>(2,0));
    //     for(int index = n-1;index>=0;index--){
    //         for(int buy = 1;buy >=0;buy--){
    //             if(buy){
    //                 dp[index][buy] = max(-prices[index]+dp[index+1][false],dp[index+1][buy]);
    //             }else{
    //                 dp[index][buy] = max(prices[index]-fee+dp[index+1][true], dp[index+1][buy]);
    //             }
    //         }
    //     }
    //     return dp[0][true];
    // }