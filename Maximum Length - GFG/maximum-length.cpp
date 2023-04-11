//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int maxi = max(a , max(b , c));
        int mini = min(a , min(b , c));
        int mid;
        if(a==maxi && b == mini){
            mid = c;
        }else if(a==maxi && c == mini){
            mid = b;
        }else if(b == maxi && c == mini){
            mid = a;
        }else if( b == maxi && a == mini){
            mid = c;
        }else if(c == maxi && a == mini){
            mid = b;
        }else{
            mid = a;
        }
        if(2*(mid+mini) >= maxi){
            return a+b+c;
        }else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends