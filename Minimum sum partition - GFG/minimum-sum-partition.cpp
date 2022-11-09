//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    vector<int> ans;
    void solve(int arr[],int n,int i,int sum,int now){
        if(i==n){
            return;
        }
        ans.push_back((sum-now));
        solve(arr,n,i+1,sum,now+arr[i]);
        solve(arr,n,i+1,sum,now);
        return;
    }
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    int temp = sum;
	    sum/=2;
	    int dp[n+1][sum+1];
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<sum+1;j++){
	            if(i==0){
	                dp[i][j] = false;
	            }
	            if(j==0){
	                dp[i][j] = true;
	            }
	        }
	    }
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<sum+1;j++){
	            if(arr[i-1] <= j){
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    int one;
	    for(int i=sum;i>=0;i--){
	        if(dp[n][i] == true){
	            one =i;
	            break;
	        }
	    }
	    return temp-(2*one);
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends