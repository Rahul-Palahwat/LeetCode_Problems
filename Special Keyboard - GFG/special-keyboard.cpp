//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int n)
    {
      if(n<=6)
      return n;
      
      vector<long long>temp(n+1,0);
      for(int i=1;i<=6;i++)
      temp[i]=i;
      
      for(int i=7;i<=n;i++)
      {
          int mul = 3;
          for(int j=i-5;j<i;j++){
              temp[i] = max(temp[j]+(mul*temp[j]) , temp[i]);
              mul--;
          }
      }
      return temp[n];
      
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends