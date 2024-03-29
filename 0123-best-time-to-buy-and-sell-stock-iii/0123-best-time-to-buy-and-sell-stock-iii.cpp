class Solution {
public:
    
    // Recursion + Memoization
    // int solve(vector<int>& prices , int index , int buy , int cnt,vector<vector<vector<int>>>& dp){
    //     if(index == prices.size()){
    //         return 0;
    //     }
    //     if(cnt >= 2){
    //         return 0;
    //     }
    //     if(dp[index][buy][cnt] != -1){
    //         return dp[index][buy][cnt];
    //     }
    //     int profit = 0;
    //     if(buy){
    //         int take = -prices[index] + solve(prices , index+1 , false , cnt,dp);
    //         int notTake = solve(prices , index+1 , buy , cnt,dp);
    //         profit = max(take , notTake);
    //     }else{
    //         int take = prices[index]+solve(prices , index+1 , true , cnt+1,dp);
    //         int notTake = solve(prices , index+1 , buy , cnt,dp);
    //         profit = max(take , notTake);
    //     }
    //     return dp[index][buy][cnt] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3,-1)));
    //     return solve(prices , 0 , true , 0 , dp);
    // }
    
    
    
    // Tabulation
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(3,0)));
    //     for(int index=n-1;index>=0;index--){
    //         for(int buy = 0;buy<=1;buy++){
    //             for(int cnt=2;cnt>0;cnt--){
    //                 int profit = 0;
    //                 if(buy){
    //                     int take = -prices[index] + dp[index+1][false][cnt];
    //                     int notTake = dp[index+1][buy][cnt];
    //                     profit = max(take , notTake);
    //                 }else{
    //                     int take = prices[index]+dp[index+1][true][cnt-1];
    //                     int notTake = dp[index+1][buy][cnt];
    //                     profit = max(take , notTake);
    //                 }
    //                 dp[index][buy][cnt] = profit;
    //             }
    //         }
    //     }
    //     return dp[0][true][2];
    // }
    
    
    
    
    // Tabulation + Optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2 , vector<int>(3,0));
        vector<vector<int>> cur(2 , vector<int>(3,0));
        for(int index=n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int cnt=2;cnt>0;cnt--){
                    int profit = 0;
                    if(buy){
                        int take = -prices[index] + prev[false][cnt];
                        int notTake = prev[buy][cnt];
                        profit = max(take , notTake);
                    }else{
                        int take = prices[index]+prev[true][cnt-1];
                        int notTake = prev[buy][cnt];
                        profit = max(take , notTake);
                    }
                    cur[buy][cnt] = profit;
                }
            }
            prev= cur;
        }
        return prev[true][2];
    }
};