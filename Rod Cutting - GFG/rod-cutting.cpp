//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int price[] , int len , vector<int>& dp){
        if(len < 0){
            return 0;
        }
        if(dp[len] != -1){
            return dp[len];
        }
        int ans = price[len];
        for(int i=0;i<len;i++){
            ans = max(ans , solve(price , i ,dp) + solve(price , len-i-1 ,dp));
        }
        return dp[len] = ans;
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1 , -1);
        return solve(price , n-1 , dp);
    }
    
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