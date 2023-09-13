//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        string ans = "";
        if(S == 0 && N>1){
            return "-1"; 
        }
        while(S >= 0 && N > 0){
            int temp = S/9;
            if(temp >= 1){
                ans+='9';
                S-=9;
            }else{
                ans+=to_string(S);
                S = 0;
            }
            N--;
        }
        if(N == 0 && S == 0){
            return ans;
        }
        return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends