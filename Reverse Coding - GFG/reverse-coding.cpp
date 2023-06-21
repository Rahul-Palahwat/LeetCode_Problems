//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int MOD = 1e9+7;
    int sumOfNaturals(int n) {
        // code here
        if(n%2 == 0){
            long long ans = ((n/2)*1LL*(n+1))%MOD;
            return ans;
        }else{
            long long ans = (n*1LL*((n+1)/2))%MOD;
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends