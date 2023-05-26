//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int MOD = 1e9+7;
    int solve(int n , int sum , int index , int x , vector<vector<int>>& dp){
        if(sum > n){
            return 0;
        }
        if(sum == n){
            return 1;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        if(pow(index , x) > n){
            return 0;
        }
        int notTake = solve(n,sum , index+1 , x ,dp);
        int take = solve(n , sum+pow(index , x) , index+1 , x , dp);
        return dp[index][sum] = (take+notTake)%MOD;
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<int>> dp(n+n+n , vector<int>(n+n+n , -1));
        return solve(n , 0 , 1 , x ,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends