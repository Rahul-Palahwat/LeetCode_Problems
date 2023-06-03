class Solution {
public:
    int solve(vector<int>& prices , int index , int buy , int cnt,vector<vector<vector<int>>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(cnt >= 2){
            return 0;
        }
        if(dp[index][buy][cnt] != -1){
            return dp[index][buy][cnt];
        }
        int profit = 0;
        if(buy){
            int take = -prices[index] + solve(prices , index+1 , false , cnt,dp);
            int notTake = solve(prices , index+1 , buy , cnt,dp);
            profit = max(take , notTake);
        }else{
            int take = prices[index]+solve(prices , index+1 , true , cnt+1,dp);
            int notTake = solve(prices , index+1 , buy , cnt,dp);
            profit = max(take , notTake);
        }
        return dp[index][buy][cnt] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<int> ans;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3,-1)));
        return solve(prices , 0 , true , 0 , dp);
    }
};