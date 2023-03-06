//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        string s = "";
        while(n>0){
            if(n&1){
                s+="1";
            }else{
                s+="0";
            }
            n>>=1;
        }
        int sz = s.length();
        reverse(s.begin(),s.end());
        for(int i=0;i<sz-2;i++){
            if(s[i] == s[i+1] && s[i+1] == s[i+2] && s[i] == '1'){
                s[i+2] = '0';
                i+=1;
            }
        }
        reverse(s.begin(),s.end());
        int ans = 0;
        for(int i=0;i<sz;i++){
            if(s[i] == '1'){
                ans+=(1<<i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends