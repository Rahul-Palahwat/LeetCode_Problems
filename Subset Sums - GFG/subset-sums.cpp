//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    void solve(int index, vector<int> &arr, int sum, bool taken){
        if(index >= arr.size()){
            if(sum != 0){
                ans.push_back(sum);
            }else if(taken){
                ans.push_back(sum);
            }
            return;
        }
        solve(index+1 , arr , sum, taken);
        solve(index+1 , arr , sum+arr[index], true);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        ans.push_back(0);
        solve(0 , arr, 0, false);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends