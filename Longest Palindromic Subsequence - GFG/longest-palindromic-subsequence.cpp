//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
//     int solve(int i , int j , string s1 , string s2 , vector<vector<int>> &dp){
// 	        if(i == s1.size() || j == s2.size()){
// 	            return 0;
// 	        }
// 	        if(dp[i][j] != -1){
// 	            return dp[i][j];
// 	        }
// 	        int ans = 0;
// 	        if(s1[i] == s2[j]){
// 	            return dp[i][j] = 1+solve(i+1 , j+1 , s1 , s2 , dp);
// 	        }else{
// 	            return dp[i][j] = max(solve(i+1 , j , s1 , s2 , dp) , solve(i , j+1 , s1 , s2 , dp));
// 	        }
// 	}
    int longestPalinSubseq(string str) {
        //code here
        int n = str.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        string s1 = str;
		reverse(str.begin() , str.end());
		string s2 = str;
		for(int i=n-1;i>=0;i--){
		    for(int j=n-1;j>=0;j--){
		        if(s1[i] == s2[j]){
	                dp[i][j] = 1+dp[i+1][j+1];
    	        }else{
    	            dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
    	        }
		    }
		}
		return dp[0][0];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends