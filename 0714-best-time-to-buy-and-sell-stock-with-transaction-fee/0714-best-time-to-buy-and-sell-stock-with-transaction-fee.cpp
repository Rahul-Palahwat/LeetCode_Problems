class Solution {
public:
    int solve(int index , bool buy , vector<int>& prices , int fee , vector<vector<int>>& dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        if(buy){
            return dp[index][buy] = max(-prices[index]+solve(index+1,false,prices,fee , dp),solve(index+1,buy,prices,fee ,dp));
        }
        return dp[index][buy] = max(prices[index]-fee+solve(index+1,true,prices,fee , dp) , solve(index+1,buy,prices,fee , dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2,-1));
        return solve(0 , true , prices , fee , dp);
    }
};