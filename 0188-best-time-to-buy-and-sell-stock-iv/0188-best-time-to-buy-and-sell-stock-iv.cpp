class Solution {
public:
    // Recursion + Memoization
    // int solve(int ind , int k , bool buy , vector<int>& prices , vector<vector<vector<int>>> &dp){
    //     if(ind >= prices.size()){
    //         return 0;
    //     }
    //     if(k<=0){
    //         return 0;
    //     }
    //     if(dp[ind][buy][k] != -1){
    //         return dp[ind][buy][k];
    //     }
    //     if(buy){
    //         return dp[ind][buy][k] = max((-prices[ind] + solve(ind+1 , k , false , prices , dp)) , (solve(ind+1 , k , buy , prices , dp)));
    //     }else{
    //         return dp[ind][buy][k] =max((prices[ind]+solve(ind+1 , k-1 , true , prices , dp)) , solve(ind+1 , k , buy , prices , dp));
    //     }
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
    //     return solve(0 , k , true , prices , dp);
    // }
    
    
    // Tabulation
    // int maxProfit(int cnt, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(cnt+1 , 0)));
    //     for(int ind = n-1;ind>=0;ind--){
    //         for(int buy = 0;buy<=1;buy++){
    //             for(int k=cnt;k>0;k--){
    //                 if(buy){
    //                     dp[ind][buy][k] = max((-prices[ind] + dp[ind+1][false][k]),dp[ind+1][buy][k]);
    //                 }else{
    //                     dp[ind][buy][k] =max((prices[ind]+dp[ind+1][true][k-1]) , dp[ind+1][buy][k]);
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0][true][cnt];
    // }
    
    
    // Tabulation + Optimization
    int maxProfit(int cnt, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2 , vector<int>(cnt+1 , 0));
        vector<vector<int>> cur(2 , vector<int>(cnt+1 , 0));
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int k=cnt;k>0;k--){
                    if(buy){
                        cur[buy][k] = max((-prices[ind] + prev[false][k]),prev[buy][k]);
                    }else{
                        cur[buy][k] =max((prices[ind]+prev[true][k-1]) , prev[buy][k]);
                    }
                }
            }
            prev = cur;
        }
        return cur[true][cnt];
    }
};