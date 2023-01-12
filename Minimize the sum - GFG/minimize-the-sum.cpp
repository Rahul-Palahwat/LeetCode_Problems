//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        int sum = 0;
        priority_queue<int,vector<int>,greater<int>> minh;
        for(auto it: arr){
            minh.push(it);
        }
        while(minh.size() > 1){
            int t1 = minh.top();
            minh.pop();
            int t2 = minh.top();
            minh.pop();
            minh.push(t1+t2);
            sum+=(t1+t2);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends