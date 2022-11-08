//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    // My solution
    // vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    // {
    //     // code here
    //     sort(Arr,Arr+N,greater<long long int>());
    //     vector<long long int> ans;
    //     long long int temp=0;
    //     for(int i=0;i<N-1;i++){
    //         temp = temp^Arr[i];
    //         if(Arr[i] != Arr[i+1]){
    //             if(temp != 0){
    //                 ans.push_back(temp);
    //                 temp=0;
    //             }
    //         }
    //     }
    //     if(ans.size()==1){
    //         ans.push_back(Arr[N-1]);
    //     }
    //     // sort(ans.begin(),ans.end)
    //     return ans;
    // }
     vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        long long x = 0;
        for(int i=0;i<n;i++)
            x ^= arr[i];
            
        long long temp = 1;
        while((temp&x)==0)
            temp <<= 1;
            
        long long a = 0, b = 0;
        for(int i=0;i<n;i++){
            if(temp&arr[i])
                a ^= arr[i];
            else
                b ^= arr[i];
        }
        
        if(a<b)
            swap(a,b);
            
        return {a,b};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends