//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    // Write your code here.
    int cnta = 0 , cntb = 0 , flag=0;
    int n = s.length();
    for(int i=0;i<n;){
        if(i<n)
        if(s[i] == 'a'){
            cnta++;
            while(s[i] == 'a'){
                i++;
            }
        }else{
            cntb++;
            while(s[i] == 'b'){
                i++;
            }
        }
    }
    // cout<<cnta<<" "<<cntb<<endl;
    return min(cnta , cntb)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends