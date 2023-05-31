//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
    // code here
    map<int, int> mp;
    for (int i=0;i<n;i++) {
        mp[arr[i]]++;
    }
    map<int, vector<int>> mini;
    for (pair<int,int> it : mp) {
        mini[it.second].push_back(it.first);
    }
    pair<int, vector<int>> start = *(mini.begin());
    return start.second[start.second.size() - 1];
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends