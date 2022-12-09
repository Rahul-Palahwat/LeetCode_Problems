//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)

{

    int mod = 1e9+7;

    long long ans=((long long)N*M-1)*N*M%mod;

    if(N>1 && M>2) ans=(ans-4*((long long)N-1)*(M-2)%mod)%mod;

    if(M>1 && N>2) ans=(ans-4*((long long)M-1)*(N-2)%mod)%mod;

    return ans;

}