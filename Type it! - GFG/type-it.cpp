//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    
  public:
    int minOperation(string s) {
        // code here
        int n = s.length();
        int maxi = 0;
        string temp = "";
        for(int i=0;i<n;i++){
            string t = "";
            for(int j=i;j<n;j++){
                t+=s[j];
                if(t.length() > temp.length()){
                    break;
                }
                if(t == temp){
                    int len = t.length();
                    maxi = max(maxi , len);
                    break;
                }
            }
            temp+=s[i];
        }
        if(maxi > 0){
            return n-maxi+1;
        }
        return n-maxi;
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
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends