class Solution {
public:
    
    int solve(vector<int>& prices , int index , bool check , vector<vector<int>>& dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][check] != -1){
            return dp[index][check];
        }
        int profit = 0;
        if(check){
            int notTaken = solve(prices , index+1 , check , dp);
            int taken =prices[index] + solve(prices , index+1 , false , dp);
            profit = max(notTaken , taken);
        }else{
            int notTaken = solve(prices , index+1 , check , dp);
            int taken = - prices[index] + solve(prices , index+1 , true , dp);
            profit = max(taken , notTaken);
        }
        return dp[index][check] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2,-1)); 
        return solve(prices , 0 , false , dp);
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