//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

// int solve(int start , int end, string str, vector<vector<int>> &dp){
//     if(start >= end){
//         return 0;
//     }
//     if(dp[start][end] != -1){
//         return dp[start][end];
//     }
//     if(str[start] == str[end]){
//         return dp[start][end] = solve(start+1 , end-1 , str , dp);
//     }else{
//         return dp[start][end] = 1+min(solve(start+1 , end , str , dp) , solve(start , end-1 , str , dp));
//     }
// }
// int minDeletions(string str, int n) { 
//     //complete the function here 
//     vector<vector<int>> dp(n , vector<int>(n,-1));
//     return solve(0 , n-1 , str , dp);
// } 


int solve(int start , int end, string str, vector<vector<int>> &dp){
    if(start >= end){
        return 0;
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }
    if(str[start] == str[end]){
        return dp[start][end] = solve(start+1 , end-1 , str , dp);
    }else{
        return dp[start][end] = 1+min(solve(start+1 , end , str , dp) , solve(start , end-1 , str , dp));
    }
}
int minDeletions(string str, int n) { 
    //complete the function here 
    string s1 = str;
    reverse(str.begin() , str.end());
    string s2 = str;
    vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return n-dp[n][n];
    return solve(0 , n-1 , str , dp);
} 