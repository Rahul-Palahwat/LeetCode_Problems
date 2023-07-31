//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int f , int egg , vector<vector<int>>& dp){
        if(egg == 1){
            return f;
        }
        if(f <= 1){
            return f;
        }
        if(dp[f][egg] != -1){
            return dp[f][egg];
        }
        int ans = INT_MAX;
        for(int k=1;k<=f;k++){
            int notBreak = solve(f-k , egg , dp);
            int brek = solve(k-1 , egg-1 , dp);
            int temp = 1+max(brek , notBreak);
            ans = min(ans , temp);
        }
        return dp[f][egg] = ans;
    }
    int eggDrop(int n, int k)
    {
        // your code here
        vector<vector<int>> dp(k+1 , vector<int>(n+1 , -1));
        return solve(k , n , dp);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends