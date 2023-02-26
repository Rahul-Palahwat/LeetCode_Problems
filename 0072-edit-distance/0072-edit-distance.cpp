class Solution {
public:
    int ans = INT_MAX;
    int solve(string s1 , string s2 , int i , int j , vector<vector<int>>& dp){
        if(i<0){
            return j+1;
        }
        if(j< 0){
            return i+1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j]=solve(s1 , s2 , i-1 , j-1,dp);
        }else{
            return dp[i][j]=1+min(solve(s1,s2,i-1 , j,dp) , min(solve(s1,s2,i-1,j-1,dp),solve(s1,s2,i,j-1,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n , vector<int>(m,-1));
        if(n == 0 && m == 0){
            return 0;
        }
        if(n == 0 || m == 0){
            return max(n , m);
        }
        return solve(word1 , word2 , n-1 , m-1 , dp);
//         int n = word1.length();
//         int m = word2.length();
//         vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<m+1;j++){
//                 if(word2[j-1] == word1[i-1]){
//                     dp[i][j] = 1+ min(dp[i-1][j] , dp[i][j-1]);
//                 }else{
//                     dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
//                 }
//             }
//         }
//         int ans = n-dp[n][m];
//         // cout<<dp[n][m]<<endl;
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=m;j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         int i=1,flag=0;
//         string check="";
//         while(i<m){
//             while(dp[n][i] == dp[n][i+1]){
//                 if(flag == 0){
//                     check+=word2[i-1];
//                 }
//                 i++;
//                 flag=1;
//             }
//             if(flag==1){
//                 flag=0;
//             }
//             check+=word2[i];
//             i++;
            
//         }
//         cout<<check<<endl;
//         int j=0;
//         flag = 0;
//         for(int i=0;i<m;i++){
//             while(check[j] != word2[i] && flag == 0){
//                 i++;
//             }
//             flag=1;
//         }
//         return ans;
    }
};