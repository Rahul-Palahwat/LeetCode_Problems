//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // bool check(int n,int k,vector<int> stalls, int index,int prev,int mini){
    //     if(k==0){
    //         return true;
    //     }
    //     if(index == n){
    //         return false;
    //     }
    //     if(stalls[index]-prev >= mini){
    //         return check(n,k-1,stalls,index+1,stalls[index],mini);
    //     }else{
    //         return check(n,k,stalls,index+1,prev,mini);
    //     }
    // }
    bool check(int n,int k,vector<int> stalls,int dist){
        int cnt = 1;
        int prev = stalls[0];
        for(int i=1;i<n;i++){
            if((stalls[i]-prev) >= dist){
                cnt++;
                prev = stalls[i];
            }
        }
        if(cnt>=k){
            return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int mid,ans=0;
        while(low<=high){
            mid = (high+low)/2;
            // if(check(n,k-1,stalls,1,stalls[0],mid)){
            if(check(n,k,stalls,mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends