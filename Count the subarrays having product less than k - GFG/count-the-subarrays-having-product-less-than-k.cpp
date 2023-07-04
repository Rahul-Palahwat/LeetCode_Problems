//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans = 0 , start=0 , end = 0;
        long long mul = 1;
        while(end < n && start < n){
            mul=mul*1LL*a[end];
            while(mul >= k && start <= end){
                mul/=a[start];
                ans+=(end-start);
                start++;
            }
            end++;
        }
        int temp = end-start;
        while(temp > 0){
            ans+=temp;
            temp--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends