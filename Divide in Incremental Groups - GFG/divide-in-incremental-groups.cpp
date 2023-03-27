//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[101][101][201];
    int solve(int N , int k , int temp){
        if(k==0){
            return 1;
        }
        
        if(k==1){
            if(temp == 0){
                return 1;
            }
            if(temp > N){
                return 0;
            }
            temp = temp+N;
            return 1;
        }
        if(dp[N][k][temp] != -1){
            return dp[N][k][temp];
        }
        int cnt = 0;
        if(temp==0){
            for(int i=1;i<=N;i++){
                cnt+=solve(N-i , k-1 , i);
            }
        }else{
            if(temp > N){
                return 0;
            }
            for(int i = temp;i<=temp+N;i++){
                if(N-i >= 0)
                cnt+=solve(N-i , k-1 , i);
            }
        }
        return dp[N][k][temp]=cnt;
        // return cnt;
    }
    int countWaystoDivide(int N, int K) {
        // Code here
        memset(dp , -1 , sizeof(dp));
        return solve(N , K, 0);
    }
    
    
    
    
    
    // int countWaystoDivide(int N, int K) {
    //     // Code here
    //     int ans = 0;
    //     vector<int> temp;
    //     for(int i=1;i<=N;i++){
    //         for(int j=0;j<K;j++){
                
    //         }
    //     }
    //     return ans;
    // }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends