//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
// 	int solve(int index , int curr , int arr[] , int n, vector<vector<int>> &dp){
// 	    if(index > n){
// 	        return 0;
// 	    }
// 	    if(dp[index][curr] != -1){
// 	        return dp[index][curr];
// 	    }
// 	    int ans = solve(index+1 , curr , arr , n , dp);
// 	    if(curr == 0){
// 	        ans = max(ans , arr[index-1]+solve(index+1 , index , arr , n , dp));
// 	    }else if(arr[index-1] > arr[curr-1]){
// 	        ans = max(ans , arr[index-1]+solve(index+1 , index , arr , n , dp));
// 	    }
// 	    return dp[index][curr] = ans;
// 	}
// 	int maxSumIS(int arr[], int n)  
// 	{  
// 	    // Your code goes here
// 	    vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
// 	    return solve(1 , 0 , arr , n , dp);
// 	}


	int maxSumIS(int arr[], int n) {
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> dp(n+1 , 0);
    
        for (int i = 1; i <= n; i++) {
            vector<int> prev(n+1 , 0);
            for (int j = 0; j < i; j++) {
                prev[j] = max(prev[j], dp[j]);
    
                if (j == 0 || arr[i - 1] > arr[j - 1]) {
                    prev[i] = max(prev[i], arr[i - 1] + dp[j]);
                }
            }
            dp = prev;
        }
    
        int maxSum = 0;
        for (int i = 0; i <= n; i++) {
            maxSum = max(maxSum, dp[i]);
        }
    
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends