class Solution {
public:
    int MOD = 1e9+7;
    // vector<vector<int>> dp;
//     long long helper(int &n, int &k, int songs, int goals){
//         if(songs==n && goals==0)
//             return 1;
//         if(goals == 0) // songs != 0
//             return 0;
        
//         if(dp[songs][goals]!=-1)
//             return dp[songs][goals];
        
//         long long res = 0;
//         if(songs<n) // take new num(options = songs that are not yet listened)
//             res += helper(n, k, songs + 1, goals-1)*(n - songs)%MOD; 
//         if(songs>k) // repeat num(options = already_listened_songs - k)
//             res += helper(n, k, songs, goals-1)*(songs - k)%MOD; 
        
//         return dp[songs][goals] = res%MOD;
//     }
    
    int numMusicPlaylists(int n, int goal, int k) {
        // dp.resize(n + 1, vector<int>(goal + 1, 0));
        // return helper(n, k, 0, goal);
        
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, 0));
        dp[n][0] = 1;
        for(int i = n; i >= 0; i--){
            for(int j = 1; j <= goal; j++){
                if(i < n)
                    dp[i][j] += dp[i+1][j-1]*(n-i) % MOD;
                if(i > k)
                    dp[i][j] += dp[i][j-1]*(i-k) % MOD;
        
                dp[i][j] %= MOD;
            }
        }
        
        return dp[0][goal];
    }
};