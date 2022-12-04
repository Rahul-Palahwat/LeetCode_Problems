//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    // vector<vector<int>> ans;
    // void solve(vector<int> arr , int index,vector<int>& temp){
    //     if(index == arr.size()){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     vector<int> t = temp;
    //     t.push_back(arr[index]);
    //     solve(arr,index+1,t);
    //     solve(arr,index+1,temp);
    //     return;
        
    // }
    // vector<int> subsetSums(vector<int> arr, int N)
    // {
    //     vector<int> temp,final;
    //     solve(arr,0,temp);
    //     // cout<<ans.size();
    //     for(auto it: ans){
    //         int sum=0;
    //         for(auto iti:it){
    //             sum+=iti;
    //         }
    //         final.push_back(sum);
    //     }
    //     return final;
    //     // Write Your Code here
    // }
    vector<vector<int>> all;
    void solve(vector<int> arr, int index , vector<int> temp){
        if(index >= arr.size()){
            all.push_back(temp);
            return;
        }
        vector<int> t1=temp;
        temp.push_back(arr[index]);
        solve(arr,index+1,t1);
        solve(arr,index+1,temp);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans,final;
        solve(arr,0,ans);
        for(auto it: all){
            int sum = 0;
            for(auto i : it){
                sum+=i;
            }
            final.push_back(sum);
        }
        return final;
        
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