class Solution {
public:
    int MOD = 1e9+7;
    int solve(int i , int j,vector<vector<int>>& grid, vector<vector<int>> &dp){
        int ans = 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(((i-1) >=0) && (grid[i-1][j] > grid[i][j])){
            ans=(ans + 1 + solve(i-1 , j , grid , dp))%MOD;
        }
        if(((j-1) >= 0) && (grid[i][j-1] > grid[i][j])){
            ans=(ans + 1 + solve(i , j-1 , grid , dp))%MOD;
        }
        if(((i+1)<grid.size()) && (grid[i+1][j] > grid[i][j])){
            ans=(ans + 1 + solve(i+1 , j , grid , dp))%MOD;
        }
        if(((j+1)<grid[0].size()) && (grid[i][j+1] > grid[i][j])){
            ans=(ans + 1 + solve(i , j+1 , grid ,dp))%MOD;
        }
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = (n*m)%MOD;
        vector<vector<int>> dp(n , vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp = solve(i, j, grid , dp);
                ans = (ans+temp)%MOD;
            }
        }
        return ans;
    }
};