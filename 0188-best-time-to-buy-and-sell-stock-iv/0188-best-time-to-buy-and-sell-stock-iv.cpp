class Solution {
public:
    int solve(int ind , int k , bool buy , vector<int>& prices , vector<vector<vector<int>>> &dp){
        if(ind >= prices.size()){
            return 0;
        }
        if(k<=0){
            return 0;
        }
        if(dp[ind][buy][k] != -1){
            return dp[ind][buy][k];
        }
        if(buy){
            return dp[ind][buy][k] = max((-prices[ind] + solve(ind+1 , k , false , prices , dp)) , (solve(ind+1 , k , buy , prices , dp)));
        }else{
            return dp[ind][buy][k] =max((prices[ind]+solve(ind+1 , k-1 , true , prices , dp)) , solve(ind+1 , k , buy , prices , dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        return solve(0 , k , true , prices , dp);
    }
};