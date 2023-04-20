class Solution {
public:
    // Recursion approach 
//     int solve(vector<vector<int>>& matrix , int i , int j){
//         int n = matrix.size();
//         if(i == 0){
//             return matrix[i][j];
//         }
//         int ans = INT_MAX;
//         if(j==0 && n>1){
//             ans =matrix[i][j] + min(solve(matrix , i-1 , j) , solve(matrix , i-1 , j+1));
//         }else if(j==0){
//             ans = matrix[i][j]+solve(matrix , i-1 , j);
//         }else if(j==n-1){
//             ans = matrix[i][j]+min(solve(matrix , i-1 , j) , solve(matrix , i-1 , j-1));
//         }else{
//             ans = matrix[i][j]+min(solve(matrix , i-1 , j) , min(solve(matrix , i-1 , j+1) , solve(matrix , i-1 , j-1)));
//         }
//         return ans;
        
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int ans = INT_MAX;
//         for(int i=0;i<n;i++){
//             ans = min(ans , solve(matrix , n-1 , i));
//         }
//         return ans;
//     }
    
    
    // Recursion + memoization
//     int solve(vector<vector<int>>& matrix , int i , int j , vector<vector<int>>& dp){
//         int n = matrix.size();
//         if(i == 0){
//             return matrix[i][j];
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int ans = INT_MAX;
//         if(j==0 && n>1){
//             ans =matrix[i][j] + min(solve(matrix , i-1 , j , dp) , solve(matrix , i-1 , j+1 , dp));
//         }else if(j==0){
//             ans = matrix[i][j]+solve(matrix , i-1 , j , dp);
//         }else if(j==n-1){
//             ans = matrix[i][j]+min(solve(matrix , i-1 , j , dp) , solve(matrix , i-1 , j-1 , dp));
//         }else{
//             ans = matrix[i][j]+min(solve(matrix , i-1 , j , dp) , min(solve(matrix , i-1 , j+1 , dp) , solve(matrix , i-1 , j-1 , dp)));
//         }
//         return dp[i][j] = ans;
        
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n , vector<int>(n , -1));
//         int ans = INT_MAX;
//         for(int i=0;i<n;i++){
//             ans = min(ans , solve(matrix , n-1 , i , dp));
//         }
//         return ans;
//     }
    
    
    
    // Tabluation DP , bottom up
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>> dp(n , vector<int>(n,0));
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0){
    //                 dp[i][j] = matrix[i][j];
    //             }else{
    //                 if(j == 0){
    //                     dp[i][j] = matrix[i][j]+min(dp[i-1][j] , dp[i-1][j+1]);
    //                 }else if(j == n-1){
    //                     dp[i][j] = matrix[i][j]+min(dp[i-1][j] , dp[i-1][j-1]);
    //                 }else{
    //                     dp[i][j] = matrix[i][j]+min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i-1][j+1]));
    //                 }
    //             }
    //         }
    //     }
    //     int ans = INT_MAX;
    //     for(auto it: dp[n-1]){
    //         ans = min(ans , it);
    //     }
    //     return ans;
    // }
    
    
    
     // Tabluation DP  , space optimization
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];
        for(int i=1;i<n;i++){
            vector<int> temp = matrix[i];
            for(int j=0;j<n;j++){
                if(j == 0){
                    temp[j] += min(dp[j] , dp[j+1]);
                }else if(j == n-1){
                    temp[j] += min(dp[j] , dp[j-1]);
                }else{
                    temp[j] += min(dp[j] , min(dp[j-1] , dp[j+1]));
                } 
            }
            dp = temp;
        }
        int ans = INT_MAX;
        for(auto it: dp){
            ans = min(ans , it);
        }
        return ans;
    }
};