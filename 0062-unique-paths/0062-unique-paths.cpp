class Solution {
public:
    int ans = 1;
    int solve(int i , int j , int n , int m,vector<vector<int>>& dp){
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(i>= n || j>=m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int first =solve(i+1 , j , n , m , dp);
        int second =solve(i , j+1 , n , m , dp);
        dp[i][j] = first+second;
        return ans=dp[i][j];
    }
    int uniquePaths(int m, int n) {
        if(m == 1 || n==1){
            return 1;
        }
        vector<vector<int>> dp(n, vector<int>(m , -1));
        solve(0 , 0 , n , m , dp);
        return ans;
    }
};