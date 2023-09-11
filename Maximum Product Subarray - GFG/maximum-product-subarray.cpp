//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans = INT_MIN;
	    long long prod1 = 1, prod2 =1;
	    bool flag = false;
	    int maxi = INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        maxi = max(maxi , arr[i]);
	        if(arr[i] == 0){
	            prod1 = 1;
	            prod2 = 1;
	            flag = false;
	            continue;
	        }
	        prod1 *= arr[i];
	        if(prod1 < 0 || flag == true){
	            if(flag){
	                prod2 *= arr[i];
	                ans = max(ans , prod2);
	            }
	            flag = true;
	        }
	        ans = max(ans , prod1);
	    }
	    if(maxi > ans){
	        return maxi;
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
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends