//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> ans(n , 0) , boundSum;
        vector<int> temp = arr;
        sort(temp.begin() , temp.end());
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=temp[i];
            boundSum.push_back(sum);
        }
        for(int i=0;i<n;i++){
            int index = (upper_bound(temp.begin() , temp.end() , arr[i]-1)-temp.begin())-1;
            if(index >= 0){
                ans[i] = boundSum[index];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends