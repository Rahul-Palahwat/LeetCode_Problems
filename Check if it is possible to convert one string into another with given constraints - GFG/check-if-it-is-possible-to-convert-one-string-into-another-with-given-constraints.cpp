//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        if(M!=N){
            return 0;
        }
        stack<char> st1;
        for(int i=0;i<S.length();i++){
            if(S[i] == 'A' || S[i] == 'B'){
                st1.push(S[i]);
            }
        }
        for(int i=T.length()-1;i>=0;i--){
            if(T[i] == 'A' || T[i] == 'B'){
                if(st1.size()==0){
                    return 0;
                }
                if(st1.top() != T[i]){
                    return 0;
                }else{
                    st1.pop();
                }
            }
        }
        if(st1.size()==0){
            return 1;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends