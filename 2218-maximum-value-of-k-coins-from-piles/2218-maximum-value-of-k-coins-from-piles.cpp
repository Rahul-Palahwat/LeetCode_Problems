class Solution {
public:
    // int solve(vector<vector<int>>& piles , int k,vector<int> index ,vector<vector<vector<int>>>& dp){
    //     if(k <= 0){
    //         return 0;
    //     }
    //     // if(dp[index][k] !=-1){
    //     //     return dp[index][k];
    //     // }
    //     int ans = 0 , n  = piles.size();
    //     for(int i=0;i<n;i++){
    //         if(index[i] < piles[i].size()){
    //             index[i]++;
    //             ans = max(ans , piles[i][index[i]-1]+solve(piles , k-1 , index , dp));
    //             index[i]--;
    //         }
    //     }
    //     return ans;
    //     // return dp[index][k] = ans;
    // }
    // int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    //     int n = piles.size();
    //     vector<int> index(n , 0);
    //     vector<vector<vector<int>>> dp(n , vector<vector<int>>(n , vector<int>(n , -1)));
    //     return solve(piles , k , index , dp);
    // }
    
    int maxValueOfCoins(vector<vector<int>>& A, int K) {
        int n = A.size();
        vector<vector<int>> memo(n + 1, vector<int>(K + 1, 0));
        function<int(int, int)> dp = [&](int i, int k) {
            if (memo[i][k] > 0) return memo[i][k];
            if (i == n || k == 0) return 0;
            int res = dp(i + 1, k), cur = 0;
            for (int j = 0; j < A[i].size() && j < k; ++j) {
                cur += A[i][j];
                res = max(res, dp(i + 1, k - j - 1) + cur);
            }
            memo[i][k] = res;
            return res;
        };
        return dp(0, K);
    }
};