//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int start = 0 , end = 0;
            for(int i=0;i<n-1;i++){
                if(a[i]%2 == a[i+1]%2){
                    end = i+1;
                }else{
                    sort(a.begin()+start , a.begin()+end+1 , greater<int>());
                    start = i+1;
                    end = i+1;
                }
            }
            sort(a.begin()+start , a.begin()+end+1 , greater<int>());
            return a;
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
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends