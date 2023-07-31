class Solution {
public:
    int solve(int i , int j , string &s1 , string &s2, vector<vector<int>> &dp){
        if(i<0 && j<0){
            return 0;
        }
        if(i<0){
            int ans = 0;
            for(int k=j;k>=0;k--){
                ans+=s2[k];
            }
            return ans;
        }
        if(j<0){
            int ans = 0;
            for(int k=i;k>=0;k--){
                ans+=s1[k];
            }
            return ans;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        if(s1[i] == s2[j]){
            ans = min(ans , solve(i-1 , j-1 , s1 , s2 , dp));
        }else{
            ans = min(ans , s1[i]+solve(i-1 , j , s1 , s2 , dp));
            ans = min(ans , s2[j]+solve(i , j-1 , s1 , s2 , dp));
        }
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return solve(n-1 , m-1 , s1 , s2 , dp);
    }
};