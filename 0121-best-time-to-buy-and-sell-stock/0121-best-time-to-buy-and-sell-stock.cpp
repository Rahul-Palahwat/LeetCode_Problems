class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size() , maxi=prices[0],mini = prices[0];
        vector<int> dp(n , 0);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            if(mini > prices[i]){
                mini = prices[i];
                maxi = prices[i];
            }else{
                maxi = max(prices[i] , maxi);
            }
            dp[i] = max(dp[i-1] , maxi-mini);
        }
        return dp[n-1];
    }
};