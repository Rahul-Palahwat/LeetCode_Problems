class Solution {
public:
    int MOD = 1e9+7;
    int solve(int prev, int rem, int cnt, int m, vector<vector<vector<int>>> &dp){
        if(rem == 0 && cnt == 0){
            return 1;
        }
        if(rem <= 0 || cnt < 0){
            return 0;
        }
        if(dp[prev][rem][cnt] != -1){
            return dp[prev][rem][cnt];
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            if(i>prev){
                ans= (ans+solve(i, rem-1 , cnt-1 , m , dp))%MOD;
            }else{
                ans= (ans + solve(prev, rem-1 , cnt , m , dp))%MOD;
            }
        }
        return dp[prev][rem][cnt] = ans;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 , vector<int>(k+1, -1)));
        int ans = 0;
        for(int i=1;i<=m;i++){
            ans=(ans + solve(i, n-1 , k-1 , m , dp))%MOD;
        }
        return ans;
    }
};