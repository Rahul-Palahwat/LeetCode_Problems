//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // Recursion + Memoization
    // int solve(int index , int W , int wt[] , int val[] , vector<vector<int>> &dp){
    //     if(index < 0){
    //         return 0;
    //     }
    //     if(dp[index][W] != -1){
    //         return dp[index][W];
    //     }
    //     int taken = 0 , notTaken = 0;
    //     notTaken = solve(index-1 , W , wt , val , dp);
    //     if(wt[index] <= W){
    //         taken = val[index]+solve(index-1 , W-wt[index] , wt , val , dp);
    //     }
    //     return dp[index][W] = max(taken , notTaken);
    // }
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //   // Your code here
    //   vector<vector<int>> dp(n , vector<int>(W+1 , -1));
    //   return solve(n-1 , W , wt , val , dp);
    // }
    
    
    
    // Tabulation
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1 , vector<int>(W+1 , 0));
       for(int index=1;index<=n;index++){
           for(int w=0;w<=W;w++){
               int taken = 0 , notTaken = 0;
                notTaken = dp[index-1][w];
                if(wt[index-1] <= w){
                    taken = val[index-1]+dp[index-1][w-wt[index-1]];
                }
                dp[index][w] = max(taken , notTaken);
           }
       }
       return dp[n][W];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends