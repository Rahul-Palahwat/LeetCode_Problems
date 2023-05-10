//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        int ans = 0;
        vector<int> post(N,0);
        int mini = INT_MAX;
        for(int i=N-1;i>=0;i--){
            mini = min(mini , A[i]);
            post[i] = mini;
        }
        int maxi=INT_MIN;
        for(int i=0;i<N-1;i++){
            maxi = max(maxi , A[i]);
            int sum = maxi+post[i+1];
            if(sum >= K){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends