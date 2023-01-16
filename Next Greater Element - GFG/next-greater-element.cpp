//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans(n,-1);
        priority_queue< long long , vector<long long> , greater<long long> > minh;
        minh.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(minh.size() > 0 && minh.top() <= arr[i]){
                minh.pop();
            }
            if(minh.size() > 0){
                ans[i] = minh.top();
            }
            minh.push(arr[i]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends