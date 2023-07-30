//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int index , int prev , int arr[] , vector<vector<int>> &dp){
	    if(index <= 0){
	        return 0;
	    }
	    if(dp[index][prev] != -1){
	        return dp[index][prev];
	    }
	    int notTaken = solve(index-1 , prev , arr ,dp);
	    int taken = 0;
	    if(prev == 0){
	        taken = arr[index-1]+solve(index-1 , index , arr , dp);
	    }else{
	        if(arr[index-1] < arr[prev-1]){
	            taken = arr[index-1]+solve(index-1 , index , arr , dp);
	        }
	    }
	    return dp[index][prev] = max(taken , notTaken);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
	    return solve(n , 0 , arr , dp);
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