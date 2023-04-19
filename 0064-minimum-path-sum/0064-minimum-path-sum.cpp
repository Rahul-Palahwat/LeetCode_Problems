class Solution {
public:
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(i-1 == 0 && j-1 == 0){
    //                 dp[i][j] = grid[i-1][j-1];
    //             }else if(i-1 == 0){
    //                 dp[i][j] = grid[i-1][j-1]+dp[i][j-1];
    //             }else if(j-1 == 0){
    //                 dp[i][j] = grid[i-1][j-1]+dp[i-1][j];
    //             }else{
    //                 dp[i][j] = min(dp[i-1][j] , dp[i][j-1])+grid[i-1][j-1];
    //             }
    //         }
    //     }
    //     for(int i=0;i<=n;i++){
    //         for(int j=0;j<=m;j++){
    //             cout<<dp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return dp[n][m];
    // }
    
    
    
    
    
    
    // my Approach using recursion
//     int ans = INT_MAX;
//     void solve(vector<vector<int>>& grid , int i,int j , int temp){
//         if(i==grid.size()-1 && j==grid[0].size()-1){
//             ans = min(ans , temp+grid[i][j]);
//             return;
//         }
//         if(i>=grid.size() || j>=grid[0].size()){
//             return;
//         }
//         solve(grid , i+1 , j , temp+grid[i][j]);
//         solve(grid , i , j+1 , temp+grid[i][j]);
//         return;
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size() , m = grid[0].size();
//         solve(grid, 0 , 0 , 0);
//         return ans;
  
//     }
    
    
    // Now recursion and then memoization 
    // int solve(vector<vector<int>>& grid , int i,int j , vector<vector<int>>& dp){
    //     if(i==0 && j==0){
    //         return grid[i][j];
    //     }
    //     if(i<0 || j<0){
    //         return INT_MAX;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int ans1 = solve(grid , i-1 , j ,dp);
    //     int ans2 = solve(grid , i , j-1 , dp);
    //     if(ans1 != INT_MAX || ans2 != INT_MAX)
    //         return dp[i][j] = grid[i][j]+min(ans1 , ans2);
    //     else
    //         return INT_MAX;
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size() , m = grid[0].size();
    //     vector<vector<int>> dp(n , vector<int>(m , -1));
    //     return solve(grid, n-1 , m-1 , dp);
    // }
    
    
    
    // Now tabulation 
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp(n , vector<int>(m , 0));
        dp[0][0] = grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                    continue;
                else if(i == 0)
                    dp[i][j] = grid[i][j]+dp[i][j-1];
                else if(j==0)
                    dp[i][j] = grid[i][j]+dp[i-1][j];
                else
                    dp[i][j] = grid[i][j]+min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};