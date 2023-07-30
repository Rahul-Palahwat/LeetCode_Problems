class Solution {
public:
    int solve(int start , int end , string s , vector<vector<int>>& dp){
        if(start > end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int x = start;
        while(x<end && s[x] == s[x+1]){
            x++;
        }
        int ans = 1+solve(x+1 , end , s , dp);
        for(int i=x+1;i<=end;i++){
            if(s[i] == s[start]){
                ans = min(ans , solve(x , i-1 , s , dp)+solve(i+1 , end , s , dp));
            }
        }
        return dp[start][end] = ans;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(0 , n-1 , s , dp);
        // return solve(0 , n-1 , s , dp);
    }
};