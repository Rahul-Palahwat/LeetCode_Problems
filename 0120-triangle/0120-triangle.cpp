class Solution {
public:
    int ans = INT_MAX;
    int solve(vector<vector<int>>& triangles , int i , int j,vector<vector<int>>& dp){
        if(i == triangles.size()-1){
            return min(triangles[i][j] , triangles[i][j]);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans1 = solve(triangles , i+1 , j , dp);
        int ans2 = solve(triangles , i+1 , j+1 , dp);
        return dp[i][j] = triangles[i][j]+min(ans1 , ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(triangle , 0 , 0 , dp);
    }
};