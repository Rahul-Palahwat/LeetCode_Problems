class Solution {
public:
    // Recursion + Memoization
    // int solve(vector<int>& prices , int index , bool check , vector<vector<int>>& dp){
    //     if(index >= prices.size()){
    //         return 0;
    //     }
    //     if(dp[index][check] != -1){
    //         return dp[index][check];
    //     }
    //     int profit = 0;
    //     if(check){
    //         int notTaken = solve(prices , index+1 , check , dp);
    //         int taken =prices[index] + solve(prices , index+1 , false , dp);
    //         profit = max(notTaken , taken);
    //     }else{
    //         int notTaken = solve(prices , index+1 , check , dp);
    //         int taken = - prices[index] + solve(prices , index+1 , true , dp);
    //         profit = max(taken , notTaken);
    //     }
    //     return dp[index][check] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n , vector<int>(2,-1)); 
    //     return solve(prices , 0 , false , dp);
    // }
    
    
    
    // Tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2,0));
        dp[n][0] = 0 , dp[n][1] = 0;
        for(int index=n-1;index>=0;index--){
            for(int check=0;check<=1;check++){
                int profit = INT_MIN;
                if(check){
                    int notTaken = dp[index+1][1];
                    int taken =prices[index] + dp[index+1][0];
                    profit = max(notTaken , taken);
                }else{
                    int notTaken = dp[index+1][0];
                    int taken = - prices[index] + dp[index+1][1];
                    profit = max(taken , notTaken);
                }
                dp[index][check] = profit;
            }
        }
        return dp[0][0];
    }
    
    
    
    // int maxProfit(vector<int>& prices) {
    //     int n =prices.size();
    //     vector<int> dp(n , 0);
    //     dp[0] = 0;
    //     for(int i=1;i<n;i++){
    //         if(prices[i]-prices[i-1] > 0){
    //             dp[i] = dp[i-1]+(prices[i]-prices[i-1]);
    //         }else{
    //             dp[i] = dp[i-1];
    //         }
    //     }
    //     return dp[n-1];
    // }
};