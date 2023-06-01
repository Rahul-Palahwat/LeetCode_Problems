class Solution {
public:
    int solve(string s1 , string s2 , int i , int j , vector<vector<int>>& dp){
        if(j<0){
            return max(0 , i+1);
        }
        if(i<0){
            return max(0,j+1);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int notTaken = 1+min(solve(s1 , s2 , i , j-1 ,dp) , solve(s1 , s2 , i-1 , j-1 , dp));
        notTaken = min(notTaken , 1+solve(s1 , s2 , i-1 , j , dp));
        int taken = INT_MAX;
        if(s1[i] == s2[j]){
            taken = solve(s1 ,s2 , i-1 , j-1 , dp);
        }
        return dp[i][j] = min(taken , notTaken);
    }
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(word1 , word2 , n-1 , m-1,dp);
    }
};