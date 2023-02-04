//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1){
	        return arr[0];
	    }
	    if(n==2){
	        return max(arr[0] , arr[1]);
	    }
	    int dp[n];
	    dp[0] = arr[0];
	    dp[1] = arr[1];
	    dp[2] = arr[0]+arr[2];
	    for(int i=3;i<n;i++){
	        dp[i] = max(arr[i]+dp[i-2] , arr[i]+dp[i-3]);
	    }
	    return max(dp[n-1] , dp[n-2]);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends