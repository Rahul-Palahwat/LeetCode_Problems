class Solution {
public:
    int solve(int f , int eggs, vector<vector<int>> &dp){
        if(eggs<=1 || f<=1){
            return f;
        }
        if(dp[f][eggs] != -1){
            return dp[f][eggs];
        }
        int ans = INT_MAX;
        for(int i=1;i<=f;i++){
            int nhiTuta = solve(f-i , eggs , dp);
            int tutGaya = solve(i-1 , eggs-1 , dp);
            int temp = 1+max(nhiTuta , tutGaya);
            ans = min(ans , temp);
        }
        return dp[f][eggs] = ans;
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1 , vector<int>(3 , -1));
        return solve(n , 2 , dp);
    }
};