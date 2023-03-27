class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i-1 == 0 && j-1 == 0){
                    dp[i][j] = grid[i-1][j-1];
                }else if(i-1 == 0){
                    dp[i][j] = grid[i-1][j-1]+dp[i][j-1];
                }else if(j-1 == 0){
                    dp[i][j] = grid[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j] = min(dp[i-1][j] , dp[i][j-1])+grid[i-1][j-1];
                }
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[n][m];
    }
};