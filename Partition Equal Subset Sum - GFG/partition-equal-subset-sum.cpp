//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int arr[], int index , long long sum, vector<vector<long long>> &dp){
        if(index<0){
            return sum == 0;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        bool ans = solve(arr , index-1 , sum, dp);
        if(arr[index] <= sum){
            ans = ans || solve(arr, index-1 , sum-arr[index] , dp);
        }
        return dp[index][sum] = ans;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        long long sum = 0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2 != 0){
            return 0;
        }
        sum/=2;
        vector<vector<long long>> dp(N , vector<long long>(sum+1 , -1));
        return solve(arr , N-1 , sum , dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends