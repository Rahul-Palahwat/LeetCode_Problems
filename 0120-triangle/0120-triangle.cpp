class Solution {
public:
    // recursion and memoization
    // int solve(vector<vector<int>>& triangles , int i , int j,vector<vector<int>>& dp){
    //     if(i == triangles.size()-1){
    //         return min(triangles[i][j] , triangles[i][j]);
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int ans1 = solve(triangles , i+1 , j , dp);
    //     int ans2 = solve(triangles , i+1 , j+1 , dp);
    //     return dp[i][j] = triangles[i][j]+min(ans1 , ans2);
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n , vector<int>(n , -1));
    //     return solve(triangle , 0 , 0 , dp);
    // }
    
    
    
    // dp bottom up , tabulation 
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     for(int i=1;i<n;i++){
    //         int sz = triangle[i].size();
    //         for(int j=0;j<sz;j++){
    //             if(j == 0){
    //                 triangle[i][j]+=triangle[i-1][j];
    //             }else if(j == sz-1){
    //                 triangle[i][j]+=triangle[i-1][j-1];
    //             }else{
    //                 triangle[i][j]+=min(triangle[i-1][j-1] , triangle[i-1][j]);
    //             }
    //         }
    //     }
    //     int ans = INT_MAX;
    //     for(auto it: triangle[n-1]){
    //         ans = min(ans , it);
    //     }
    //     return ans;
    // }
    
    
    // Another approach 
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev = triangle[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int> curr=triangle[i];
            for(int j=0;j<curr.size();j++){
                curr[j]+=min(prev[j] , prev[j+1]);
            }
            prev = curr;
        }
        return prev[0];
    }
};