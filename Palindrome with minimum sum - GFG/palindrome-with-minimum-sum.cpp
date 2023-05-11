//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int ans = 0;
        int n = s.length()-1,i=0;
        while(i<n){
            if(s[i] != s[n]){
                if(s[i] != '?' && s[n] != '?'){
                    return -1;
                }
            }
            if(s[i] == '?'){
                s[i] = s[n];
            }
            if(s[n] == '?'){
                s[n] = s[i];
            }
            i++;
            n--;
        }
        int flag=0;
        char temp;
        for(int i=0;i<s.length();i++){
            if(s[i] != '?'){
                temp = s[i];
                flag=1;
                break;
            }
        }
        if(flag == 0){
            return 0;
        }
        n = s.length()-1;i=0;
        while(i<n){
            if(s[i] == '?'){
                s[i] = temp;
                s[n] = temp;
            }else{
                temp = s[i];
            }
            i++;
            n--;
        }
        for(int i=1;i<s.length();i++){
            ans += abs(s[i]-s[i-1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends