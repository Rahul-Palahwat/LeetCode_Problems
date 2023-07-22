class Solution {
public:
    vector<pair<int,int>> moves = {{2 , 1} , {-2 , -1} , {-2 , 1}, {2 , -1} , {1 , 2}, {-1 , -2}, {-1 , 2}, {1 , -2}};
    double solve(int n , int k , int i , int j , vector<vector<vector<double>>> &dp){
        if(i>=n || i<0 || j>=n || j<0){
            return 0.0;
        }
        if(k == 0){
            return 1.0;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        double ans = 0.0;
        for(auto it: moves){
            ans+=solve(n , k-1 , i+it.first , j+it.second , dp)/8.0;
        }
        return dp[i][j][k] = ans;
    }
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>> dp(n , vector<vector<double>>(n , vector<double>(k+1 , -1)));
        return solve(n , k , r , c , dp);
    }
};