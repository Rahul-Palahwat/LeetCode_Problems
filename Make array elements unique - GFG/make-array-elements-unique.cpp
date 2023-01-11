//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        long long ans=0;
        sort(arr.begin(),arr.end());
        // int maxi = arr[N-1];
        int mini = arr[0];
        unordered_map<int,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: arr){
            if(mp[it] > 1){
                while(mp[it] > 1){
                    if(mini < it){
                        mini = it;
                    }
                    while(mp.find(mini) != mp.end()){
                        mini++;
                    }
                    ans+=(mini - it);
                    mp[it]--;
                    mini++;
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends