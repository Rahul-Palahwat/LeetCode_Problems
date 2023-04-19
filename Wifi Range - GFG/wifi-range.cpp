//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        int start = 0;
        for(int i=1;i<=N;i++){
            if(S[i-1] == '1' && start == 0){
                if(i-1 > X){
                    return false;
                }
                start = i+X;
            }else if(S[i-1] == '1'){
                if(start+X+1 < i){
                    return false;
                }
                start = i+X;
            }
        }
        if(start < N){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends