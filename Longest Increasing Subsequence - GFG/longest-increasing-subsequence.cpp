//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    // int sz;
    // int solve(int index , int prev , int s[], vector<vector<int>> &dp){
    //     if(index<0){
    //         return 0;
    //     }
    //     if(dp[index][prev] != -1){
    //         return dp[index][prev];
    //     }
    //     int notTaken = solve(index-1 , prev , s , dp);
    //     int taken = INT_MIN;
    //     if(prev == sz){
    //         taken = 1+solve(index-1 , index , s , dp);
    //     }else{
    //         if(s[index] < s[prev]){
    //             taken = 1+solve(index-1 , index , s , dp);
    //         }
    //     }
    //     return dp[index][prev] = max(taken , notTaken);
    // }
    int longestSubsequence(int n, int nums[])
    {
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }else{
                int index = lower_bound(dp.begin() , dp.end() , nums[i]) - dp.begin();
                dp[index] = nums[i];
            }
        }
        return dp.size();
    //   return solve(n-1,n ,a , dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends