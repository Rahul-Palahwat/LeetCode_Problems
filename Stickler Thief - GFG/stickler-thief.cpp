//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    // memoized recursion solution 
    
    // vector<vector<int>> dp;
    // int solve(int arr[] , int ind , int flag){
    //     if(ind < 0){
    //         return 0;
    //     }
    //     if(dp[ind][flag] != -1){
    //         return dp[ind][flag];
    //     }
    //     int one=0 , two = 0;
    //     if(flag == 0){
    //         one = arr[ind]+solve(arr , ind-1 ,1);
    //     }
    //     two = solve(arr , ind-1 , 0);
    //     return dp[ind][flag]=max(one, two);
    // }
    // int FindMaxSum(int arr[], int n)
    // {
    //     // Your code here
    //     dp.resize(n,vector<int>(2,-1));
    //     if(n==1){
    //         return arr[0];
    //     }
    //     if(n==2){
    //         return max(arr[0] , arr[1]);
    //     }
    //     return solve(arr , n-1 , 0);
    // }
    
    
    
    // dp solution tabulation
        
     int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==1){
            return arr[0];
        }
        if(n==2){
            return max(arr[0] , arr[1]);
        }
        vector<int> dp(n,0);
        dp[0] = arr[0];
        dp[1] = arr[1];
        dp[2] = max(dp[1] ,arr[2]+dp[0]);
        for(int i=3;i<n;i++){
            dp[i] = max(arr[i]+dp[i-2] , max(dp[i-1] , arr[i]+dp[i-3]));
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends