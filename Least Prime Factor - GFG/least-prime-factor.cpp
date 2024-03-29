//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  bool isPrime(int n){
      for(int i=2;(i*i)<=n;i++){
          if(n%i == 0){
              return false;
          }
      }
      return true;
  }
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> ans(n+1,1);
        ans[0] = 0;
        int i=2;
        while(i <= n){
            if(isPrime(i)){
                int k = i;
                while(k<=n){
                    if(ans[k] == 1){
                        ans[k] = i;
                    }
                    k+=i;
                }
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends