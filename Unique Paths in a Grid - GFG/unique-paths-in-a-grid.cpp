//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        long long ans = 0;
        long long dp[n+1][m+1];
        memset(dp , -1 , sizeof(dp));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }
        if(grid[0][0] == 0 || grid[n-1][m-1] == 0){
            return ans;
        }
        long long MOD = 1e9+7;
        dp[1][1] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(grid[i-1][j-1] == 0){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] =max(dp[i][j] , dp[i-1][j] + dp[i][j-1]);
                    dp[i][j] %= MOD;
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends