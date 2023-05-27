//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
//   Brute force approach and then optimize by memoization
    // int solve(int price[] , int len , vector<int>& dp){
    //     if(len < 0){
    //         return 0;
    //     }
    //     if(dp[len] != -1){
    //         return dp[len];
    //     }
    //     int ans = price[len];
    //     for(int i=0;i<len;i++){
    //         ans = max(ans , solve(price , i ,dp) + solve(price , len-i-1 ,dp));
    //     }
    //     return dp[len] = ans;
    // }
    // int cutRod(int price[], int n) {
    //     //code here
    //     vector<int> dp(n+1 , -1);
    //     return solve(price , n-1 , dp);
    // }
    
    
    
    // Now converting this problem into knapsack with given weight as N
    int solve(int price[] , int index,int len , vector<vector<int>>& dp){
        if(index == 0){
            return len*price[0];
        }
        if(dp[index][len] != -1){
            return dp[index][len];
        }
        int notTake = solve(price , index-1 , len , dp) , take=0;
        if(len >= index+1){
            take = price[index]+solve(price , index , len-index-1 , dp);
        }
        return dp[index][len] = max(take , notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return solve(price , n-1 , n , dp);
    }
    
    
    
    // Tabulation 
    // int cutRod(int price[], int n) {
    //     //code here
    //     vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
    //     for(int i=0;i<n+1;i++){
    //         dp[i][0] = 1;
    //     }
    //     // dp[0][0]=0;
    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<n+1;j++){
    //             int notTake = dp[i-1][j] , take = 0;
    //             if(j>= i){
    //                 take = price[i-1]+dp[i][j-i];
    //             }
    //             dp[i][j] = max(take , notTake);
    //         }
    //     }
    //     return dp[n][n]-1;
    // }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends