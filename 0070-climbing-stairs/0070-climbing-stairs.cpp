class Solution {
public:
    int ans = 0;
    int dp[50] = {-1};
    void reset(){
        memset(dp , -1 , sizeof(dp));
    }
    int climbStairs(int n) {
        reset();
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3 ;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
        // return ans;
    }
};