class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int maxi = prices[0];
        int mini = prices[0];
        int dp[prices.size()];
        dp[0]=0;
        for(int i=1;i<prices.size();i++){
            if(mini > prices[i]){
                mini=prices[i];
                maxi = prices[i];
            }else{
                maxi=max(maxi,prices[i]); 
            }
            dp[i] = max(dp[i-1],maxi-mini);
        }
        return dp[prices.size()-1];
    }
};