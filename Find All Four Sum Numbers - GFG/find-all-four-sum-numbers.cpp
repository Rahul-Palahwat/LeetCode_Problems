//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        set<vector<int>> ans;
        sort(arr.begin() , arr.end());
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int s = j+1 , e = n-1;
                int find = k-arr[i]-arr[j];
                while(s<e){
                    if(arr[s]+arr[e] == find){
                        ans.insert({arr[i] , arr[j] , arr[s] , arr[e]});
                        s++;
                        while(s<n && arr[s-1] == arr[s]){
                            s++;
                        }
                        e--;
                        while(e>=s && arr[e] == arr[e+1]){
                            e--;
                        }
                    }else if(arr[s]+arr[e] > find){
                        e--;
                    }else{
                        s++;
                    }
                }
            }
        }
        vector<vector<int>> finalAns;
        for(auto it: ans){
            finalAns.push_back(it);
        }
        return finalAns;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends